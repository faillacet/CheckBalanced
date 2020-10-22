#ifndef READFILE_H
#define READFILE_h

#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadFile {
private:
    bool balanced;          //not sure if this serves a purpose either
    int countLine = 0;      // THIS is used to determine which line the error occurs on
    int countOP = 0;        //dont think i ever even used these :(
    int countOB = 0;
    int countOCB = 0;
    int countCP = 0;
    int countCB = 0;
    int countCCB = 0;
    bool exit = false;
 public:
    ReadFile();
    ~ReadFile();
    bool checkBalance(string file, GenStack<char> &stack);
    bool getExit();
};

#endif