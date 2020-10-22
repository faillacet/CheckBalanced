#include "ReadFile.h"

ReadFile::ReadFile() {
    balanced = false;
}

ReadFile::~ReadFile() {
    
}

bool ReadFile::checkBalance(string file, GenStack<char> &stack) {           //essentially the beef of the program
    ifstream myFile(file);                                                  //handels the actually checking of balance
    if (myFile.is_open()) {
        string temp;
        char check = 'Y';
        while (getline(myFile,temp)) {
            countLine++;
            for (int i =0;i<temp.length();++i) {
                if (temp[i]=='{') {
                    stack.push(temp[i]);
                    countOCB++;
                }
                else if (temp[i]=='(') {
                    stack.push(temp[i]);
                    countOP++;
                }
                else if (temp[i]=='[') {
                    stack.push(temp[i]);
                    countOB++;
                }
                else if (temp[i]=='}') {
                    check = stack.peek();
                    if (check == '\0') {
                        cout << "No opening bracket found at line: " << countLine << endl;
                        return false;
                    }
                    else if (check != '{') {
                        cout << "Operator mismatch at line: " << countLine << " --- { expected but " << check << " found." << endl;
                        return false;
                    }
                    else {
                        stack.pop();
                    }
                    countCCB++;
                }
                else if (temp[i]==')') {
                    check =stack.peek();
                    if (check == '\0') {
                        cout << "No opening parentesis found at line: " << countLine <<endl;
                        return false;
                    }
                    else if (check != '(') {
                        cout << "Operator mismatch at line: " << countLine << " --- ( expected but " << check << " found." <<endl;
                        return false;
                    }
                    else {
                        stack.pop();
                    }
                    countCP++;
                }
                else if (temp[i]==']') {
                    check = stack.peek();
                    if (check == '\0') {
                        cout << "No opening bracket found at line: " << countLine << endl;
                        return false;
                    }
                    else if (check != '[') {
                        cout << "Operator mismatch at line: " << countLine << " --- [ expected but " << check << " found." << endl;
                        return false;
                    }
                    else {
                        stack.pop();
                    }
                    countCB++;
                }
            }
        }
        myFile.close();
        if (stack.isEmpty()==true) {
            cout << "File is balanced!"<<endl;
            return true;
        }
        check = stack.peek();
        if (check == '{') {
            check = '}';
        }
        else if (check == '(') {
            check = ')';
        }
        cout << "Reached end of file. Missing: " << check << endl;
        return false;        
    }
    else {
        cout << "Error Opening file!" <<endl;
        return false;
    }
}

bool ReadFile::getExit() {
    return exit;
}