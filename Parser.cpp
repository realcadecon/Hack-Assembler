// File: Parser.cpp
// Author: Cade Conner
// Date: 4/5/2020
// Section: 510
// E-mail: cadejconner@tamu.edu 
// Description: Parser function definitions
// e.g. The content of this file implements ..

#include "Parser.h"

using namespace std;

    Parser::Parser(string& filename){
        file = filename;
        inData.open(file);
        if(!inData.is_open()){
            cout<<"Error: Unable to open file <filename>"<<endl;
        }
        addrs["R0"] = 0;
        addrs["R1"] = 1;
        addrs["R2"] = 2;
        addrs["R3"] = 3;
        addrs["R4"] = 4;
        addrs["R5"] = 5;
        addrs["R6"] = 6;
        addrs["R7"] = 7;
        addrs["R8"] = 8;
        addrs["R9"] = 9;
        addrs["R10"] = 10;
        addrs["R11"] = 11;
        addrs["R12"] = 12;
        addrs["R13"] = 13;
        addrs["R14"] = 14;
        addrs["R15"] = 15;
        addrs["SCREEN"] = 16384;
        addrs["KBD"] = 24576;
        addrs["SP"] = 0;
        addrs["LCL"] = 1;
        addrs["ARG"] = 2;
        addrs["THIS"] = 3;
        addrs["THAT"] = 4;
        customVar = 16;
    }

    Parser::~Parser(){
        inData.close();
    }
    // functions deal with a instruction command table and managing new commands
    int Parser::addr(string mnemonic){
        return addrs[mnemonic];
    }
    bool Parser::addrsContains(string mnemonic){
        if(addrs.find(mnemonic) == addrs.end()){
            return false;
        }
        else{
            return true;
        }
    }
    void Parser::addCommmand(string mnemonic, int lineNum){
        addrs[mnemonic] = lineNum;
    }
    string Parser::toBinary(string decimal){
        int numD = stoi(decimal);
        string numB;
         while(numD!=0) {
            numB = (numD%2==0 ?"0":"1") + numB; 
            numD/=2;
        }
        while(numB.length()!=15){
            numB = "0" + numB;
        }
        return numB;
    }
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    //Erases comments and white space and passes everything into a vector
    void Parser::parse(int lineNum){
        string currLine;
        //Commands =instA;
        while(getline(inData, currLine)){

            for(int i=0; i<currLine.length();i++){ //remove comments
                if(currLine[i]=='/'){
                currLine.erase(i, currLine.length());
                }
                currLine.erase(remove_if(currLine.begin(), currLine.end(), ::isspace), currLine.end());
            }
            if(currLine.find_first_not_of(' ') != -1 && currLine.find('(') == -1){
                assembly.push_back(currLine);
                lineNum++;
            }
            if(currLine.find('(')!=-1){
                string newCom = currLine.substr(currLine.find('(')+1, currLine.find(')')-1);
                addCommmand(newCom, lineNum);
            }
        }
    }

    //reads through vector of instructions and decodes them into machine code
    void Parser::getInstructions(int lineNum){
        ofstream outData;
        string outfile = "default.hack";
        if(file.find("/")!=-1){
            outfile = file.substr(file.find_last_of("/")+1, file.length());
        }
        else{
            outfile = file.substr(0, file.find_last_of("."));
        }
        outfile = outfile.substr(0, outfile.find(".")) + ".hack";
        outData.open(outfile);
        string output="";
        for(int i=0; i<assembly.size(); i++){ //goes through vector that contains parsed instrcutions
            if(assembly[i].find('@') != -1){
                output = getAInstruction(assembly[i]);
                //cout<<assembly[i]<<endl; //testing----------------
            }
            else if(assembly[i][0] == 'A' || assembly[i][0] == 'D' || assembly[i][0] == 'M' || isdigit(assembly[i][0])){
                output = getCInstruction(assembly[i]);
            }
            else if(assembly[i][0] == '(' ){
                 output = "";
            }
            outData<<output<<endl;
        }
    }

    //takes in @"address" and returns the machine code for the a instruction
    string Parser::getAInstruction(string address){
        string adr = address.substr(1, address.length());
        if(isdigit(adr[0])){
            adr = "0" + toBinary(adr); 
        }
        else if(!addrsContains(adr)){
            addCommmand(adr, customVar);
            customVar++;
            int temp = addrs[adr];
            string adrVal = to_string(temp); 
            adr = "0" + toBinary(adrVal);
        }
        else{
            int temp = addrs[adr];
            string adrVal = to_string(temp); 
            adr = "0" + toBinary(adrVal);
        }
        return adr;
    }

    //takes in symbolic c instruction and returns the machine code for the c instruction
    string Parser::getCInstruction(string inst){
        int numChar = inst.length();
        string jump;
        string dest;
        string comp;

        if(inst.find('J')!=-1){ //handles jump command
            jump = inst.substr(inst.find('J'),inst.length());
            numChar-=3;
        }
        else{
            jump ="null";
            comp = inst.substr(inst.find('=')+1, inst.length());
        }
        if(inst.find('=')!=-1){ //handles destination command
            dest = inst.substr(0,inst.find("="));
        }
        else{
            dest = "null";
            comp = inst.substr(0, inst.find(';'));
        }
        if(inst.find('=')!=-1 && inst.find(';')!=-1){
            comp = inst.substr(inst.find('=')+1, inst.find(';'));
        }
        Commands cinst;
        //cout<<"comp = "<<comp<<" | dest = "<<dest<<" | jump = "<<jump<<endl;
        inst = "111" + cinst.comp(comp) + cinst.dest(dest) + cinst.jump(jump);
        return inst;
    }