#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;

// a new type for the sack
typedef struct {
    string firstHalf;
    string secondHalf;
} Sack;

// Takes in a sack struct and returns its score
int sackScore(Sack sack){
    int score = 0;
    string found = "";
    for (int i = 0; i < sack.firstHalf.length(); i++){
        // if the letter we are looking at is in the second half
        // and isn't in the "found" string
        if (sack.secondHalf.find(sack.firstHalf[i]) != string::npos && found.find(sack.firstHalf[i]) == string::npos){
            found.append(string(1,sack.firstHalf[i]));

            if (sack.firstHalf[i] >= 97){
                // making 'a' have a score of 1
                score += sack.firstHalf[i] - ('a' - 1);
            }
            else if (sack.firstHalf[i] >= 'A'){
                // making 'A' have a score of 27
                score += sack.firstHalf[i] - 38;
            }
        }
    }

    return score;
}


int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    int totalScore = 0;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            Sack sack;
            sack.firstHalf = line.substr(0, line.length()/2);
            sack.secondHalf = line.substr(line.length()/2, line.length()-1);
            totalScore += sackScore(sack);
        }

        std::cout << totalScore << '\n';

        inputFile.close();
    }

    return 0;
}
