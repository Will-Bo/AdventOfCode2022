#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;

struct {
    char opponent;
    char you;
} outcome;

int calculateScore(int O, int Y){
    int roundScore = 0;
    // shape you selected
    if (Y == 'X'){
        roundScore += 1;
    }
    else if (Y == 'Y'){
        roundScore += 2;
    }
    else if (Y == 'Z'){
        roundScore += 3;
    }
    // outcome
    if ((Y == 'X' && O == 'C') || (Y == 'Y' && O == 'A') || (Y == 'Z' && O == 'B')){
        roundScore += 6;
    }
    else if ((Y == 'X' && O == 'A') || (Y == 'Y' && O == 'B') || (Y == 'Z' && O == 'C')){
        roundScore += 3;
    }
    else{
        roundScore += 0;
    }
    return roundScore;
}

int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    int totalScore = 0;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            std::cout << line << '\n';
            // nonempty lines represent what a single elf has
            if (!line.empty()){
                outcome.opponent = line[0];
                outcome.you = line[2];
                std::cout << "Outcome: " << calculateScore(outcome.opponent, outcome.you) << '\n';
                totalScore += calculateScore(outcome.opponent, outcome.you);
            }
            else{
                // do nothing... end of program
           }
        }

        inputFile.close();
    }
    std::cout << "Your score will be " << totalScore << '\n';

    return 0;
}
