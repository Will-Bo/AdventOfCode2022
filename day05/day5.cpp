#include<iostream>
#include<fstream>
#include<string>

#include<cstring>

#include<stack>

using std::ifstream;
using std::string;

using std::stack;

void swapStacks(){
}

int main(){
    string line;
    ifstream inputFile;
    inputFile.open("information.txt");

    bool firstHalf = true;

    stack<char> stack1;
    stack<char> stack2;
    stack<char> stack3;
    stack<char> stack4;
    stack<char> stack5;
    stack<char> stack6;
    stack<char> stack7;
    stack<char> stack8;
    stack<char> stack9;

    if (inputFile.is_open()){
        while (std::getline (inputFile, line)){
            std::cout << line << '\n';
            std::cout << line[1] << ' ' << line[5] << ' ' << line[9] << ' ' << line[13] << ' ' << line[17] << ' ' << line[21] << ' ' << line[25] << ' ' << line[29] << ' ' << line[33] << '\n';

            if (firstHalf){
                if (line[1] != ' ') {
                    stack1.push(line[1]);
                }
                if (line[1] == '1' && line[5] == '2' && line[9] == '3' && line[13] == '4' && line[17] == '5' && line[21] == '6' && line[25] == '7' && line[29] == '8' && line[33] == '9'){
                    firstHalf = false;
                    stack<char> newS1;
                    while (stack1.size() != 0) {
                        newS1.push(stack1.top());
                        stack1.pop();
                    }
                    stack1 = newS1;
                }
            }
            else {
                while (stack1.size() != 0){
                    char val = stack1.top();
                    stack1.pop();
                    std::cout << val << '\n';
                }
                inputFile.close();
            }
        }

        inputFile.close();
    }

    return 0;
}
