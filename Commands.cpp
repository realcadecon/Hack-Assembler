// File: Commands.cpp
// Author: Cade Conner
// Date: 4/5/2020
// Section: 510
// E-mail: cadejconner@tamu.edu 
// Description: Functions for decoding Commands/instructions 
// e.g. The content of this file implements ..

#include "Commands.h"
using namespace std;

Commands::Commands()
{
    // List of opcodes

    dests["null"] = "000";
    dests["M"] = "001";
    dests["D"] = "010";
    dests["MD"] = "011";
    dests["A"] = "100";
    dests["AM"] = "101";
    dests["AD"] = "110";
    dests["AMD"] = "111";

    comms["0"] = "0101010";
    comms["1"] = "0111111";
    comms["-1"] = "0111010";
    comms["D"] = "0001100";
    comms["A"] = "0110000";
    comms["!D"] = "0001101";
    comms["!A"] = "0110001";
    comms["-D"] = "0001111";
    comms["-A"] = "0110011";
    comms["D+1"] = "0011111";
    comms["A+1"] = "0110111";
    comms["D-1"] = "0001110";
    comms["A-1"] = "0110010";
    comms["D+A"] = "0000010";
    comms["D-A"] = "0010011";
    comms["A-D"] = "0000111";
    comms["D&A"] = "0000000";
    comms["D|A"] = "0010101";

    comms["M"] = "1110000";
    comms["!M"] = "1110001";
    comms["-M"] = "1110011";
    comms["M+1"] = "1110111";
    comms["M-1"] = "1110010";
    comms["D+M"] = "1000010";
    comms["D-M"] = "1010011";
    comms["M-D"] = "1000111";
    comms["D&M"] = "1000000";
    comms["D|M"] = "1010101";

    jumps["null"] = "000";
    jumps["JGT"] = "001";
    jumps["JEQ"] = "010";
    jumps["JGE"] = "011";
    jumps["JLT"] = "100";
    jumps["JNE"] = "101";
    jumps["JLE"] = "110";
    jumps["JMP"] = "111";

    

}

string Commands::comp(string mnemonic) {
    return comms[mnemonic];
}
string Commands::dest(string mnemonic) {
    return dests[mnemonic];
}
string Commands::jump(string mnemonic) {
    return jumps[mnemonic];
}

Commands::~Commands(){}