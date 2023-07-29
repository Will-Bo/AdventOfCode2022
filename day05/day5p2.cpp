// Line 78 --- add line[1] != ' ', etc.
#include<iostream>
#include<fstream>
#include<string>

#include<cstring>

#include<stack>
#include<bits/stdc++.h>

using std::ifstream;
using std::string;

using std::stack;

typedef struct {
    int src;
    int dest;
    int num;
} moveInfo;

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

void moveStack(stack<char>* dest, stack<char>* src){
    stack<char> d = *dest;
    stack<char> s = *src;

    dest->push(src->top());
    src->pop();
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

            if (firstHalf){
                // end of parsing
                if (line[1] == '1' && line[5] == '2' && line[9] == '3' && line[13] == '4' && line[17] == '5' && line[21] == '6' && line[25] == '7' && line[29] == '8' && line[33] == '9'){
//                if (line[1] == '1' && line[5] == '2' && line[9] == '3'){

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

                    // This will read the blank line between the data and the movements, allowing it to be skipped
                    std::getline (inputFile, line);

                }

                // lots of copy-paste --- how to optimize?
                if (line[1] != '1' && line[1] != ' ') {
                    stack1.push(line[1]);
                }
                if (line[5] != '2' && line[5] != ' ') {
                    stack2.push(line[5]);
                }
                if (line[9] != '3' && line[9] != ' ') {
                    stack3.push(line[9]);
                }
                if (line[13] != '4' && line[13] != ' ') {
                    stack4.push(line[13]);
                }
                if (line[17] != '5' && line[17] != ' ') {
                    stack5.push(line[17]);
                }
                if (line[21] != '6' && line[21] != ' ') {
                    stack6.push(line[21]);
                }
                if (line[25] != '7' && line[25] != ' ') {
                    stack7.push(line[25]);
                }
                if (line[29] != '8' && line[29] != ' ') {
                    stack8.push(line[29]);
                }
                if (line[33] != '9' && line[33] != ' ') {
                    stack9.push(line[33]);
                }
            }
            // the stacks are complete --- now move the values between stacks
            else {

                std::stringstream ss(line);
                string word;
                int counter = 0;
                moveInfo move;
                while (ss >> word) {
                    std::cout << word << std::endl;
                    if (counter == 1){
                        move.num = std::stoi(word);
                    }
                    else if (counter == 3){
                        move.src = std::stoi(word);
                    }
                    else if (counter == 5){
                        move.dest = std::stoi(word);
                    }
                    counter++;
                }

                stack<char>* source;
                stack<char>* destination;

                switch (move.src) {
                    case 1:
                        source = &stack1;
                        break;
                    case 2:
                        source = &stack2;
                        break;
                    case 3:
                        source = &stack3;
                        break;
                    case 4:
                        source = &stack4;
                        break;
                    case 5:
                        source = &stack5;
                        break;
                    case 6:
                        source = &stack6;
                        break;
                    case 7: 
                        source = &stack7;
                        break;
                    case 8:
                        source = &stack8;
                        break;
                    case 9: 
                        source = &stack9;
                        break;
                }
                switch (move.dest) {
                    case 1:
                        destination = &stack1;
                        break;
                    case 2:
                        destination = &stack2;
                        break;
                    case 3:
                        destination = &stack3;
                        break;
                    case 4:
                        destination = &stack4;
                        break;
                    case 5:
                        destination = &stack5;
                        break;
                    case 6:
                        destination = &stack6;
                        break;
                    case 7: 
                        destination = &stack7;
                        break;
                    case 8:
                        destination = &stack8;
                        break;
                    case 9: 
                        destination = &stack9;
                        break;
                }

                // Observation: If I move 'n' boxes from the source to a temporary holder, then move those 'n' boxes from the temporary holder to the destination, their order is preserved. It's as if we moved those 'n' boxes as a block, just like in the description
                // Creating a temporary holding place
                stack<char> tmp;
                for (int i = 0; i < move.num; i++){
                    moveStack(&tmp, source);
                }
                // moving stack items as many times as the command requires
                for (int i = 0; i < move.num; i++){
                    moveStack(destination, &tmp);
                }
            }
        }

        std::cout << "Stack tops:\n";
        std::cout << stack1.top();
        std::cout << stack2.top();
        std::cout << stack3.top();
        std::cout << stack4.top();
        std::cout << stack5.top();
        std::cout << stack6.top();
        std::cout << stack7.top();
        std::cout << stack8.top();
        std::cout << stack9.top() << '\n';


        inputFile.close();
    }

    return 0;
}
