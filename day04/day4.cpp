#include<iostream>
#include<fstream>
#include<string>

#include<cstring>

using std::ifstream;
using std::string;

// a new type for the range
typedef struct {
    string range;
    int firstHalf;
    int secondHalf;
} areaRange;

// comparing if e2 is inside e1
bool comparison(areaRange e1, areaRange e2){
    if (e1.firstHalf <= e2.firstHalf && e1.secondHalf >= e2.secondHalf)
        return true;
    return false;
}

int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    int count = 0;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            // finding the separation between each elf
            int i = 0;
            while (line[i] != ','){
                i++;
            }

            // populating the elf structs --- not necessary, but makes the comparison easier
            areaRange firstElf;
            firstElf.range = line.substr(0,i);

            areaRange secondElf;
            secondElf.range = line.substr(i+1, line.length());

            firstElf.firstHalf = std::stoi(firstElf.range.substr(0, firstElf.range.find('-')));
            firstElf.secondHalf = std::stoi(firstElf.range.substr(firstElf.range.find('-') + 1, firstElf.range.length()));

            secondElf.firstHalf = std::stoi(secondElf.range.substr(0, secondElf.range.find('-')));
            secondElf.secondHalf = std::stoi(secondElf.range.substr(secondElf.range.find('-') + 1, secondElf.range.length()));

            // finding if either elf encompasses the other elf
            if (comparison(firstElf, secondElf) || comparison(secondElf, firstElf)){
                std::cout << line << '\n';
                count++;
            }
        }

        inputFile.close();
    }

    std::cout << count << '\n';

    return 0;
}
