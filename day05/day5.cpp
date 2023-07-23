#include<iostream>
#include<fstream>
#include<string>

#include<cstring>

#include<stack>

using std::ifstream;
using std::string;

using std::stack;

// memory optimization --- make this take a pointer to a stack instead
// that way you wouldn't have to pass the stack object back & forth from function
stack<char> reverseStack(stack<char> toBeSwapped){
    stack<char> newStack;
    while (toBeSwapped.size() != 0) {
        newStack.push(toBeSwapped.top());
        toBeSwapped.pop();
    }
    return newStack;
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
                // end of parsing
                if (line[1] == '1' && line[5] == '2' && line[9] == '3' && line[13] == '4' && line[17] == '5' && line[21] == '6' && line[25] == '7' && line[29] == '8' && line[33] == '9'){
                    firstHalf = false;

                    stack1 = reverseStack(stack1);
                    stack2 = reverseStack(stack2);
                    stack3 = reverseStack(stack3);
                    stack4 = reverseStack(stack4);
                    stack5 = reverseStack(stack5);
                    stack6 = reverseStack(stack6);
                    stack7 = reverseStack(stack7);
                    stack8 = reverseStack(stack8);
                    stack9 = reverseStack(stack9);

                }

                // lots of copy-paste --- how to optimize?
                if (line[1] != ' ') {
                    stack1.push(line[1]);
                }
                if (line[5] != ' ') {
                    stack2.push(line[5]);
                }
                if (line[9] != ' ') {
                    stack3.push(line[9]);
                }
                if (line[13] != ' ') {
                    stack4.push(line[13]);
                }
                if (line[17] != ' ') {
                    stack5.push(line[17]);
                }
                if (line[21] != ' ') {
                    stack6.push(line[21]);
                }
                if (line[25] != ' ') {
                    stack7.push(line[25]);
                }
                if (line[29] != ' ') {
                    stack8.push(line[29]);
                }
                if (line[33] != ' ') {
                    stack9.push(line[33]);
                }

            }
            // the stacks are complete --- now move the values between stacks
            else {
                while (stack1.size() != 0){
                    char val = stack1.top();
                    stack1.pop();
                    std::cout << val << '\n';
                }
                while (stack9.size() != 0){
                    char val = stack9.top();
                    stack9.pop();
                    std::cout << val << '\n';
                }

                inputFile.close();
            }
        }

        inputFile.close();
    }

    return 0;
}
