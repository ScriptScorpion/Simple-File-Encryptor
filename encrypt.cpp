#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

void encryptFile(const std::string& file) {
    std::ifstream in;
    in.open(file, std::ios::binary); // opens file for reading

    if (!in) {
        std::cout << "Error opening file: " << file << std::endl;
        std::exit(1);
    }

    std::filesystem::path p(file);
    std::string encryptedFile = p.replace_extension("").string() + ".enc";

    std::ofstream out;
    out.open(encryptedFile, std::ios::binary); // opens file for writing into him

    if (!out) {
        std::cout << "Error creating file: " << encryptedFile << std::endl;
        std::exit(1);
    }

    char byte;
    while (in.get(byte)) {
        out.put(~byte);
    }

    in.close();
    out.close();
    std::cout << "Encryption Done"<< std::endl;
}
int main() {
    std::string filePath;
    std::cout << "Enter file path: ";
    std::getline(std::cin, filePath);
    encryptFile(filePath);

    return 0;
}
