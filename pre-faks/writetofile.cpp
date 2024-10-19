#include <iostream>
#include <fstream>
#include <string>

int main(void){

    std::ofstream file;
    const std::string filename = "testfile.txt";
    std::string line = "";
    file.open(filename);

    auto get_line = [](std::string& line) -> bool{
        std::cout << "Unesi liniju upisa u datoteku: " << std::endl;
        std::cin >> line;
        if (line[0] == '0') return false;
        return true;
    };

    while (get_line(line)) file << line + "\n";
    file.close();

    return 0;
}