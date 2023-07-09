#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;

int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    // naive solution: just have three elves!
    // More efficient solution: max heap
    int elfNum = 1;
    int calCount = 0;

    int highestElf = 0;
    int highestCal = 0;

    int secondHighestElf = 0;
    int secondHighestCal = 0;

    int thirdHighestElf = 0;
    int thirdHighestCal = 0;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            if (!line.empty()){
                calCount += std::stoi(line);
            }
            else{
                std::cout << "Elf number " << elfNum << " had " << calCount << '\n';
                if (calCount > highestCal){
                    thirdHighestElf = secondHighestElf;
                    thirdHighestCal = secondHighestCal;

                    secondHighestElf = highestElf;
                    secondHighestCal = highestCal;

                    highestCal = calCount;
                    highestElf = elfNum;
                }
                else if (calCount > secondHighestCal){
                    thirdHighestCal = secondHighestCal;
                    secondHighestCal = calCount;
                }
                else if (calCount > thirdHighestCal){
                    thirdHighestCal = calCount;
                }

                calCount = 0;
                elfNum++;
            }
        }

        // handling the last row of data
        if (calCount > highestCal){
            thirdHighestElf = secondHighestElf;
            thirdHighestCal = secondHighestCal;

            secondHighestElf = highestElf;
            secondHighestCal = highestCal;

            highestCal = calCount;
            highestElf = elfNum;
        }
        else if (calCount > secondHighestCal){
            thirdHighestCal = secondHighestCal;
            secondHighestCal = calCount;
        }
        else if (calCount > thirdHighestCal){
            thirdHighestCal = calCount;
        }


        inputFile.close();
    }

    std::cout << highestCal+secondHighestCal+thirdHighestCal << " calories are from the three highest elves\n";

    return 0;
}
