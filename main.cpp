// File: main.cpp
// Author: Cade Conner
// Date: 4/5/2020
// Section: 510
// E-mail: cadejconner@tamu.edu 
// Description: driver file
// e.g. The content of this file implements ..

#include <iostream>
#include <map>

#include "Parser.h"

using namespace std;

//put all the .c/.cpp and .h files in that zip file mentioned above.
//Also, make sure your program compiles and generates an executable called a.out or a.exe  by using: g++ -std=c++11 *.cpp
//Make sure your program accepts one command line argument when you run it, so you should make sure the program is run with the command: ./a.out <asm file> or ./a.exe <asm file>. 


int main(int argc, char **argv){
    if(argc!=2){
        cout<<"Error: please use --> ./a.out <filename>"<<endl;
        return -1;
    }
    string filename = "";
    filename = argv[1];
    Parser newFile(filename);
    unsigned long lineNum = 0;
    newFile.parse(lineNum);  
    newFile.getInstructions(lineNum);


    return 0;
}
