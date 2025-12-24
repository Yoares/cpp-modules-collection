#include <iostream>

int main(){

    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string &stringREF = str;

    // memo address
    std::cout << &str << "\n";
    std::cout << stringPTR << "\n";
    std::cout << &stringREF << "\n";
    // value
    std::cout << str << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";
}
