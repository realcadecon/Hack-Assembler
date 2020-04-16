# Hack-Assembler
Hack Assembler written in C++
This Hack assembler reads in a ".asm" file written in Hack Assembly and outputs a ".hack" file which contains the machine code.

Example Input: 
  (Add.asm)
      *// Computes R0 = 2 + 3  (R0 refers to RAM[0])
      *@2
      *D=A
      *@3
      *D=D+A
      *@0
      *M=D
      *(START)
      *@100
      *D=A
      *@4
      *D=D-M
      *@START
      *D;JGT
      
Example Output: 
  (Add.hack)
      *0000000000000010
      *1110110000010000
      *0000000000000011
      *1110000010010000
      *0000000000000000
      *1110001100001000
      *0000000001100100
      *1110110000010000
      *0000000000000100
      *1111010011010000
      *0000000000000110
      *1110001100000001
