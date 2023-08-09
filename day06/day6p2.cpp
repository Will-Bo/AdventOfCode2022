#include<iostream>
#include<fstream>
#include<string>

#include<cstring>

#include<stack>
#include<bits/stdc++.h>

#include<map>

using std::ifstream;
using std::string;

int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            std::cout << "Line read\n" << line << '\n' ;

            // Finding each grouping in the string
            for (int i = 0; i < line.size() - 13; i++){
                // Inserting all of the elements into a map, so we know how many unique characters there are in this grouping
                std::map<char,int> m;
                for (int j = 0; j < 14; j++){
                    if(m.count(line[i+j]) == 0){
                        m.insert(std::pair<char, char>(line[i+j], 1));

                    }
                }

                // the message will start after the transmission start signal
                // transmission start signal is at `i`
                if (m.size() == 14){
                    std::cout << i+14 << '\n';
                    inputFile.close();
                    return 0;
                }
            }
        }

        inputFile.close();
    }

    return 0;
}
