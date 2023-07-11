#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;

struct {
    char opponent;
    char result;
} outcome;

int calculateScore(int O, int R){
    int roundScore = 0;
    if (R == 'X'){
        if (O == 'A') {
            // O is rock, you are scissors
            roundScore += 3;
        }
        else if (O == 'B'){
            // O is paper, you are rock
            roundScore += 1;
        }
        else if (O == 'C'){
            // O is scissors, you are paper
            roundScore += 2;
        }
    }
    else if (R == 'Y'){
        roundScore += 3;
        if (O == 'A') {
            // O is rock, you are rock 
            roundScore += 1;
        }
        else if (O == 'B'){
            // O is paper, you are paper 
            roundScore += 2;
        }
        else if (O == 'C'){
            // O is scissors, you are scissors
            roundScore += 3;
        }

    }
    else if (R == 'Z'){
        roundScore += 6;
        if (O == 'A') {
            // O is rock, you are paper
            roundScore += 2;
        }
        else if (O == 'B'){
            // O is paper, you are scissors
            roundScore += 3;
        }
        else if (O == 'C'){
            // O is scissors, you are rock 
            roundScore += 1;
        }

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
                outcome.result = line[2];
                std::cout << "Outcome: " << calculateScore(outcome.opponent, outcome.result) << '\n';
                totalScore += calculateScore(outcome.opponent, outcome.result);
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
