#include <iostream>
#include <fstream> 
#include <string>

int main(int ac, char **av){

    if (ac != 4){
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3]; 

    if (s1.empty()){
        std::cerr << "Error: s1 cannot be empty" << std::endl ;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()){
        std::cerr << "Error: cannot open input file" << std::endl ;
        return 1;
    }

    std::string content;
    std::string line;
    while (getline(infile, line, '\n')){
        content.append(line);
        if (!infile.eof())
            content += "\n";
    }
    infile.close();

    size_t pos = 0;
    size_t match = 0;
    std::string output;
    while ((match = content.find(s1, pos)) != std::string::npos)
    {
        output += content.substr(pos, match - pos);
        output += s2;
        pos = match + s1.length();
    }
    output += content.substr(pos);

    std::ofstream outfile(filename + ".replace");
    if (!outfile.is_open()){
        std::cerr << "Error: cannot create output file" << std::endl ;
        return 1;
    }
    outfile << output;
    outfile.close();
    return (0);
}