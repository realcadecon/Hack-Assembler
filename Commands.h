// File: Commands.h
// Author: Cade Conner
// Date: 4/5/2020
// Section: 510
// E-mail: cadejconner@tamu.edu 
// Description: Header for decoding Commands/instructions 
// e.g. The content of this file implements ..

#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <map>

using namespace std;

class Commands
{
    public:
        Commands();
        ~Commands();

        string dest(string mnemonic);
        string comp(string mnemonic);
        string jump(string mnemonic);

        map<string, string> comms;
        map<string, string> jumps;
        map<string, string> dests;
};

#endif 
