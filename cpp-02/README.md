This is a comprehensive guide to **C++ Module 02**. We will ignore the code for a moment and build the **mental model** from scratch. This module is a journey through creating your own number system because standard computers are actually terrible at handling decimal numbers.

---

### Part 1: The Problem (Why are we doing this?)

To understand "Fixed Point," you must understand why `float` (standard floating-point numbers) can be dangerous.

#### The "Float" Problem

In a computer, a `float` uses a complex formula (sign, exponent, mantissa) to *approximate* a number. It is like writing \frac{1}{3} as 0.333333. You eventually run out of space and stop.

* **Result:** You lose precision.
* **Example:** In some systems, `0.1 + 0.2` might equal `0.30000000000000004`.
* **Consequence:** In finance or physics, these tiny errors pile up and crash the system.

#### The "Integer" Problem

An `int` is perfect. `1 + 1` is always exactly `2`.

* **Problem:** It cannot store decimals. You cannot save `10.5`.

#### The Solution: Fixed-Point Numbers

"Fixed Point" is a clever trick. We use an **Integer** (for perfect precision) but we **pretend** a decimal point exists at a specific spot.

**The "Money" Analogy:**
Imagine you want to store `$10.50`.

* **Float:** Stores `10.5` (Might be `10.49999...`).
* **Fixed Point:** Stores `1050` (Cents).
* We store an integer: **1050**.
* We agree on a rule: "The last 2 digits are the cents."
* To read it back: 1050 / 100 = 10.50.



In this module, instead of scaling by **100**, we scale by **256** (which is 2^8) because computers love powers of 2.

---

### Part 2: Exercise 00 - The "Box" (Orthodox Canonical Form)

**Goal:** Create the basic structure to hold this number.

You create a class `Fixed`. Inside, it has exactly one integer variable:
`int _fixedPointValue;`

This integer is the "raw" value (like the 1050 cents).

* **The Bits:** An integer has 32 bits (0s and 1s).
* **The Rule:** We decide the last **8 bits** are for the "fractional" part. The other 24 bits are for the whole number.

**What is Orthodox Canonical Form?**
C++ demands strict rules for classes to prevent memory bugs. You must provide 4 specific functions for *every* class you write in this module:

1. **Default Constructor:** Creates an empty object (`Fixed a;`).
2. **Copy Constructor:** Creates a clone of an object (`Fixed b(a);`).
3. **Copy Assignment Operator:** Updates an existing object to match another (`b = c;`).
4. **Destructor:** Cleans up when the object dies.

**Summary of Ex00:** You built a box that holds an integer and follows strict safety rules. It currently only holds `0`.

---

### Part 3: Exercise 01 - The "Translation" (Int/Float Conversion)

**Goal:** Put real numbers into the box and get them out.

We need to convert human numbers (like `42.42`) into our raw storage format (like `10860`).

#### 1. The Scaling Factor (2^8 = 256)

Since we dedicated 8 bits to the fraction, our "scaling factor" is 256.

* Moving the decimal point **right** = Multiplying by 256.
* Moving the decimal point **left** = Dividing by 256.

#### 2. Storing Data (Constructors)

* **From Int to Fixed:**
* You have `10`. You want to store it.
* **Math:** 10 \times 256 = 2560.
* **Bitwise shortcut:** `10 << 8`. (Shift bits left by 8).
* *We store `2560` inside the hidden integer.*


* **From Float to Fixed:**
* You have `42.42`.
* **Math:** 42.42 \times 256 = 10859.52.
* **Rounding:** Round it to nearest integer \rightarrow `10860`.
* *We store `10860` inside the hidden integer.*



#### 3. Reading Data (Conversion functions)

* **To Float (`toFloat`):**
* Take the raw `10860`.
* Divide by 256.
* Result: `42.421875`. (Close enough to 42.42!).


* **To Int (`toInt`):**
* Take the raw `10860`.
* **Bitwise shortcut:** `10860 >> 8` (Shift bits right, discarding the fraction).
* Result: `42`.



#### 4. The Printing Operator (`<<`)

You want to type `cout << a`.
By default, C++ doesn't know how to print your class. You write a special function `operator<<` that tells C++: "When someone tries to print `Fixed`, call `.toFloat()` and print that number."

---

### Part 4: Exercise 02 - The "Calculator" (Operator Overloading)

**Goal:** Make `Fixed` behave like a normal number. We want to do `a + b` or `a > b`.

In C++, you can redefine symbols like `+`, `-`, `*`, `>`. This is called **Operator Overloading**.

#### 1. Comparisons (`>`, `<`, `==`)

This is easy. Since our numbers are just stored as integers, we just compare the raw integers.

* Is `Fixed A (10860)` > `Fixed B (2560)`?
* Yes, obviously.

#### 2. Arithmetic (`+`, `-`, `*`, `/`)

* **Addition:** Raw `256` (1.0) + Raw `256` (1.0) = Raw `512` (2.0). **Works perfectly.**
* **Multiplication (Tricky):**
* 1.0 \times 1.0 = 1.0.
* Raw `256` \times Raw `256` = `65,536`.
* Wait! `65,536` actually represents **256.0** in our system!
* **The Fix:** When multiplying, the result is "double scaled" (256 \times 256). We must divide the result by 256 to bring it back to the correct scale.



#### 3. Increment (`++`)

* `++a` means "add the smallest possible unit".
* In our system, the smallest unit is raw `1`.
* So `++` just adds `1` to the raw integer. (Mathematically, this adds \frac{1}{256} or approx `0.0039` to the real value).

---

### Part 5: Exercise 03 - The "Geometry" (BSP)

**Goal:** Use your new number system to solve a real geometric problem: **Is a point inside a triangle?**

#### 1. The Point Class

You create a class `Point` representing a 2D coordinate (x, y).

* It uses `Fixed` numbers for coordinates.
* **Constraint:** The coordinates are `const` (Constant). Once you make a point `(2, 2)`, it stays `(2, 2)` forever.

#### 2. BSP (Binary Space Partitioning)

Don't let the name scare you. It's just a method to check which "side" of a line you are on.

**The Concept: "Walking the Fence"**
Imagine a triangle ABC.

1. Stand at corner **A**, look at corner **B**.
2. Draw a line.
3. Is your point P to the **Left** of that line?
4. Now move to **B**, look at **C**. Is P to the **Left**?
5. Move to **C**, look at **A**. Is P to the **Left**?

**The Logic:**
If the point is to the **Left** (or "Inside") of **ALL THREE** lines, then the point is mathematically inside the triangle.
If it is on the "Right" (Outside) of any single line, it is outside the triangle.

**The Math (Cross Product):**
To calculate "Left or Right," we use the Vector Cross Product formula:


* Result > 0: Inside (Left).
* Result < 0: Outside (Right).
* Result = 0: On the line (Edge).

**Your Final Task (`bsp` function):**
You write a function that takes a Triangle (a, b, c) and a Point (point).

1. Calculate the cross product for Side 1 (AB).
2. Calculate for Side 2 (BC).
3. Calculate for Side 3 (CA).
4. If **all three** results are strictly positive (or strictly negative), return `True`.
5. Otherwise, return `False`.

### Summary of the Journey

1. **Ex00:** Built a container for a "raw" integer.
2. **Ex01:** Learned to translate floats into that raw integer (* 256).
3. **Ex02:** Taught C++ how to add, multiply, and compare these containers.
4. **Ex03:** Used these containers to coordinate points in 2D space and solve a geometry puzzle using vector math.