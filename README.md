# 8085-Emulator

This project is the basic implementation of 8085 microprocessor. It runs some basic commands like: -

load and store commands: MOV, MVI, LXI, LDA, STA, LHLD, SHLD, STAX, XCHG, SET (e.g. SET  2500, AB)
arithmetic commands: ADD, ADI, SUB, INR, DCR, INX, DCX, DAD, SUI
logical commands: CMA, CMP
branching commands: JMP, JC, JNC, JZ, JNZ

It also contains a debugger with the following commands:

“b” to set breakpoints followed by line numbers where you want to set breakpoints. 
  e.g.  b 12 for setting breakpoint on line 12
“r” to run the program.
“p” to print value of register or memory location.
  e.g. p A for printing value of register A
       p x2500 for printing value of location x2500
“s” to run the program, one instruction at a time
“q” to quit debugger

The emulator is designed using C++. To compile the project files, copy all the files from folder src to the main folder and type command “make” on the terminal.This will compile all the code files and create the object file “setup” which will be used to run the emulator. The emulator works on two modes of input. User can provide the code via input file (.asm) or one could also write it on the terminal. The user can run the whole code at once or he can also run it in the debugger mode. We have also provided a dummy code of bubble sort in the file bubblesort.asm(enter the address 2000 as the code is written using 2000 as the starting address).

This project is a joint contribution of:

Hardik Gaur (hardikgaur@geu.ac.in)
Parth Trehan (parthendo@geu.ac.in)

Please feel free to drop an e-mail for any suggestions and ideas.
