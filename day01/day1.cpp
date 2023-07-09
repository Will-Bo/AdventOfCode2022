#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;

int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    int elfNum = 1;
    int calCount = 0;

    int highestElf = 0;
    int highestCal = 0;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            // nonempty lines represent what a single elf has
            if (!line.empty()){
                calCount += std::stoi(line);
            }
            // empty lines indicate different elves
            else{
                std::cout << "Elf number " << elfNum << " had " << calCount << '\n';
                if (calCount > highestCal){
                    highestCal = calCount;
                    highestElf = elfNum;
                }
                // resetting cal count and moving on to the next elf
                calCount = 0;
                elfNum++;
            }
        }

        inputFile.close();
    }

    std::cout << highestCal << " calories are from elf number " << highestElf << '\n';

    return 0;
}
