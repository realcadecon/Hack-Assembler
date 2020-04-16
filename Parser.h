// File: Parser.h
// Author: Cade Conner
// Date: 4/5/2020
// Section: 510
// E-mail: cadejconner@tamu.edu 
// Description: Parser header file
// e.g. The content of this file implements ..

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "Commands.h"


class Parser {
public:
    std::vector<std::string> assembly;

    Parser(std::string& filename);
    ~Parser();

    bool hasNextCom(); //true if commands still need to be parsed
    void parse(int lineNum); //Reads file removing white-space and comments
    void getInstructions(int lineNum);//Returns A-instruction, C-instruction or Label and decodes the instruction

    void addCom(std::string com, int address); //adds new command
    bool contains(std::string com); //returns true if command is found
    int getAddress(std::string com); //returns address of command

    std::string getAInstruction(std::string address); //takes address after '@' and returns machine code for that line.
    std::string getCInstruction(std::string inst); //takes c instruction and returns machine code for that line.
    std::string getLInstruction(std::string inst, int i); //takes l instruction and line num and returns machine code for that line.
    

    std::string toBinary(std::string decimal);

    int addr(std::string mnemonic);
    bool addrsContains(std::string mnemonic);
    void addCommmand(std::string com, int lineNum);

private:
    std::ifstream inData;
    std::ofstream outData;
    int customVar;
    std::string file;
    map<std::string, int> addrs;
};


#endif