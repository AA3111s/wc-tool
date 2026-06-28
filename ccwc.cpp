#include <iostream>
#include <fstream>
#include <string>


size_t countBytes(std::istream& input){
        char buffer[8192];
        size_t totalBytes = 0;

        while(input){
            input.read(buffer, sizeof(buffer));
            totalBytes += input.gcount(); // accumulating the bytecount 
        }
        return totalBytes;
    }

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cerr << "usage: " << argv[0] << "-c <filename> \n";
        return 1;
    }
    
    std::string flag = argv[1];
    if(flag != "-c"){
        std::cerr << "Enter a valid flag.\n";
        return 1;
    }

    std::string filename = argv[2];

    std::ifstream myFile(filename, std::ios::in | std::ios::binary);

    if(!myFile.is_open()){
        //checks if the file opened successfully
        std::cerr << "failed to open file: " << filename << "\n";
        return 1;
    }

   size_t byteCount = countBytes(myFile);
   std::cout << "  " << byteCount << " " << filename << "\n";

    return 0;
}