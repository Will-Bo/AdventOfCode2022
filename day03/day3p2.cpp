#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;
// take three "sack" strings, find the common element of all 3, and then return the score
int sackScore(string sack, string sack2, string sack3){
    int score = 0;
    string found = "";
    for (int i = 0; i < sack.length(); i++){
        // if the letter is present in both of the other sacks
        // and isn't in the "found" string, then continue
        if (sack2.find(sack[i]) != string::npos && sack3.find(sack[i]) != string::npos &&found.find(sack[i]) == string::npos){
            found.append(string(1,sack[i]));

            if (sack[i] >= 97){
                // making 'a' have a score of 1
                score += sack[i] - ('a' - 1);
            }
            else if (sack[i] >= 'A'){
                // making 'A' have a score of 27
                score += sack[i] - 38;
            }
        }
    }

    return score;
}


int main(){
    string line;
    string line2;
    string line3;
    ifstream inputFile;
    inputFile.open("information.txt");

    int totalScore = 0;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            // getting the next 2 lines as well
            std::getline (inputFile, line2);
            std::getline (inputFile, line3);

            totalScore += sackScore(line, line2, line3);
        }

        std::cout << totalScore << '\n';

        inputFile.close();
    }

    return 0;
}
