#ifndef READFILE_H
#define READFILE_h

#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadFile {
private:
    bool balanced;
    int countLine = 0;
    int countOP = 0;
    int countOB = 0;
    int countCP = 0;
    int countCB = 0;
 public:
    ReadFile();
    ~ReadFile();
    bool checkBalance(string file, GenStack<char> &stack);
    bool isBalanced();
};

#endif