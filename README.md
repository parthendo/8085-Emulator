# 8085-Emulator


## Section 1: Introduction
In computing, an emulator is hardware or software that enables one computer system to behave like another computer system. An emulator typically enables the host system to run software or use peripheral devices designed for the guest system.

The current project at hand is an 8085-emulator which mimics the functionality of the 8-bit microprocessor. The 8085 microprocessor was introduced in 1976, it consisted of 8-bit data bus, registers and single byte instructions. The emulator provides a terminal to run assembly language instructions and produce outputs similar to the one obtained while working on the individual microprocessor. The emulator supports several arithmetic, increment/decrement and loading commands belonging to the 8-bit and 16-bit domain. Apart from this, the emulator also features a debugger which can set breakpoints and query the memory and the registers at a given instance to justify the working of the emulator.

Along with this, we also provide two sample programs displaying bubble-sort and addition of two numbers to display the working of the emulator.
The document is organised in the given order, section 2 lays an emphasis on the documentation required to understand the modules inside the emulator. Section 3 describes the testing scenario displaying the logic-based testing strategy where we try to display the chosen predicates follow the CACC criteria.

## Section 2: 8085-Emulator
There are 5 basic modules which constitute the entire functionality of the emulator. The 8-bit and the 16-bit commands can be categorized into four basic modules i.e.
1.   arithmetic instructions
1.  jump instructions
1. load instructions
1.  logical instructions

All the instructions mentioned above utilize the fifth module which consist the basic tools required to support all the other modules.

1. tool.h: The current file consists the definition to the functions below
 * validityData: Takes an 8-bit data and checks for its validity 
 * hexAdd: Takes two 8-bit numbers as input and adds them and set the flag registers accordingly
 * hexSub: Takes two 8-bit numbers as input and subtracts them and set the flag registers accordingly
 * hexAdd16bit: Takes two 16-bit numbers as input and adds them and set the flag registers  accordingly
 * hexSub16bit: Takes two 16-bit numbers as input and subtracts them and set the flag registers accordingly
 * decimalToHex: Takes a decimal number and converts it to equivalent hexadecimal
 * hexToDecimal: Takes an 8-bit or 16-bit number in hexadecimal and converts to decimal
 * validityRegister: Take a register in form of a string and validates the register
 * validityRegisterPair: Takes register in form of a string and validates for a valid register pair e.g. (B,C), (D,E) and (H,L) pair
 * validityHexadecimal: Takes a string and checks if it is a valid hexadecimal
 * validityFile: Takes a complete command in the form of a string and checks if the command is a valid 8085 microprocessor command
 * validityAddress: Takes a 16-bit address and checks if the current address is valid i.e. lies between 0000-FFFF
 * registerNumber: Converts a register into numeric format
 * increaseAddress: Takes a 16-bit address and increments it by 1
 * updateAddress: Takes the current program counter and based on the current command, update the program counter
 * complement: Takes a hexadecimal number and evaluates the complement of that number
 * operationSize: Computes the size compatible per operand
 * execution: Takes a command, registers, flag array, progam counter and memory to excute the current combination of instructions.

The above module helps the other modules to perform required series of actions.

1. arithmetic.h: This module wraps several arithmetic instructions for instance ADD, ADI, SUB, INR, DCR, INX, DCX, DAD, SUI. The commands have save similar functionality as defined by 8085 microprocessor.

1. jump.h: This module defines all the branching commands like JMP(jumping to a location), JC, JNC, JZ and JNZ.

1. load.h: This module defines all the load and store commands like MOV, MVI, LXI, LDA, STA, LHLD, SHLD, STAX, XCHG.

1. logical.h: This module defines all the logical instructins like CMA and CMP.

more information about the above assembly level instructions can be found on http://scandftree.com/microprocessor/Instruction-Set-In-8085


### Section 2.1: Compilation of the code
Though the executable file of the emulator is provided with the complete code, to rebuild the code, 
the program requires clang++ compiler. To install the compiler, enter the following command in the terminal

**************************************************************************************************
$ sudo apt-get install clang++	//install clang++
$ make					//rebuild the code
$ make clean				//delete the object files created in the process of rebuild
**************************************************************************************************

### Section 2.2: Run 8085-Emulator
**************************************************************************************************
$ ./emulator 				//to run the emulator on terminal
$ ./emulator addtwonumbers.asm	//to run the emulator with an assembly level file
$ ./emulator --debugger		//to enable debugger
**************************************************************************************************

### Section 2.3: Debugger
The debugger feature enables to set breakpoints and execute code in steps and query the memory and register values simultaneously to see the functionality of 8085-emulator. The features present in the debugger are
“b” to set breakpoints followed by line numbers where you want to set breakpoints. e.g. b 12 for setting breakpoint on line 12 
“r” to run the program until end of program or a breakpoint is encountered
“p” to print value of register or memory location. e.g. p A for printing value of register A p x2500 for printing value of location x2500 
“s” to run the program, one instruction at a time 
“q” to quit debugger

## Section 3: Logic-based testing strategy

We have displayed the RACC criteria while designing the testcases. The files used in logic based testing are:

i.   validityFile.cpp:
	The following method takes an instruction as an input and the predicate 
		
		if(inRecord(tokens[0]) && argumentValidation(tokens,tokens[0]) && alien(copy))
	
	is taken into consideration. The first clause checks if the opcode is present in one of the registered opcodes e.g. MOV, HLD, the second clause checks if the number of operands are correct for the 		given opcode and to check if the current set of instruction does not contain any invalid character. e.g. MOV A,B which moves the value of register B to accumulator. Each line of instruction when fed 		through a file passes through this method.
	
	pA = B && C
	pB = A && C
	pC = A && B
	   
	--------------------------------------------------
	|   A  |   B   |   C   |   P   |     Testcase    |
	--------------------------------------------------
	    T      T       T       T          MOV A,B
	    F      T       T       F          MOVE A,B
	-------------------------------------------------- 
	    T      T       T       T          SET 0004,00
	    T      F       T       F          INX H,10
	--------------------------------------------------
	    T      T       T       T          LXI H,0000
	    T      T       F       F          DCR a;
	    
	    
	    
ii.  validityHexadecimal.cpp:
	The following method takes a hexadecimal as an input and checks if it is a valid 8-bit data or 16-bit address
		
		if((l == 2 || l == 4) && checkHex(data,l))
		
	The above is the predicate of form A|B&C e.g. A0 is a valid data and 110A is a valid 16-bit address.
	The following method is reached from validityFile.cpp where it checks if the data associated with any opcode is valid.
	
	pA = B' && C
	pB = A' && C
	pC = A  || B
	
	--------------------------------------------------
	|   A  |   B   |   C   |   P   |     Testcase    |
	--------------------------------------------------
	    T      F       T       T             1E    
	    F      F       T       F            01D
	--------------------------------------------------
	    F      T       T       T           0046
	    F      F       T       F              A
	--------------------------------------------------
	    F      T       T       T           0130
	    T      F       T       T             1D
	    F      T       F       F           01H3
	    T      F       F       F             0G
	
	 
iii. SHLD.cpp
	The following method is the implementation of SHLD command. The value of HL pair or the M registers is stored in the 16-bit address provided to the method. This method is reachable from the 		execution method directly called in the main function of the emulator. The predicate under review is 
	
		if(l1 == 4 && validityAddress(arg1) && registers[5]!="" && registers[6]!="" && memory.empty() == false)
		
	Here clause A checks if length of arg1 is of length 4, clause B checks if arg1 is a valid 16-bit address in the range, clause C checks if H register is empty, clause D checks if L register empty 		and clause E checks if the memory map is empty.
	
	pA = B && C && D && E
	pB = A && C && D && E
	pC = A && B && D && E
	pD = A && B && C && E
	pE = A && B && C && D
	
	------------------------------------------------------------------
	|   A  |   B   |   C   |   D   |   E   |   P   |     Testcase    |
	------------------------------------------------------------------
	    T      T       T       T       T       T          2000, register["","","","","","01","AB"], map<1000,(MOV A,B)>
	    F      T       T       T       T       F          400,  register["","","","","","01","AB"], map<1000,(MOV A,B)> 
	    T      F       T       T       T       F          AAZA, register["","","","","","01","AB"], map<1000,(MOV A,B)>
	    T      T       F       T       T       F          2000, register["","","","","","","AB"],   map<1000,(MOV A,B)>
	    T      T       T       F       T       F          2000, register["","","","","","01",""],   map<1000,(MOV A,B)>
	    T      T       T       T       F       F          2000, register["","","","","","01","AB"], map<>
	
1.  validityData.cpp
	THe following method takes a string as an input and checks if the given data is a valid 8-bit data. The predicate checks if the length of the string is 2 i.e. 8-bit value and the first and second characters are hexadecimal or not. The clauses are A,B and C. This method acts as a helper function to all the assembly level instructions which are ADI, DAD, INX, MVI, SET and SUI.
	
		if(l==2 && isHexadecimal(a[0]) && isHexadecimal(a[1]))
```	
	pA = B && C
	pB = A && C
	pC = A && B
	
	--------------------------------------------------
	|   A  |   B   |   C   |   P   |     Testcase    |
	--------------------------------------------------
	    T      T       T       T            AB
	    F      T       T       F           100
	-------------------------------------------------- 
	    T      T       T       T            FF
	    T      F       T       F            Z1
	--------------------------------------------------
	    T      T       T       T            1A
	    T      T       F       F            1Z   
```

### Section 3.1: Executing tests or unit testing
We have used Google Test Framework for performing unit testing on the code base. Follow the commands below to perform installation of Google Test Framework and unit testing. 
```
$ cd test/GTest\ Framework/	// toggle to the GTest or the google test framework directory
$ cd ..				// toggles back to the test directory
$ cmake CMakeLists.txt		// generates the makefile for running test
$ make				// builds the executable for testing
$ ./runTests			// performs using testing
```

The emulator is designed using C++. To compile the project files, copy all the files from folder src to the main folder and type command “make” on the terminal.This will compile all the code files and create the object file “setup” which will be used to run the emulator. The emulator works on two modes of input. User can provide the code via input file (.asm) or one could also write it on the terminal. The user can run the whole code at once or he can also run it in the debugger mode. We have also provided a dummy code of bubble sort in the file bubblesort.asm(enter the address 2000 as the code is written using 2000 as the starting address).

This project is a joint contribution of:

Hardik Gaur (hardikgaur@geu.ac.in)
Parth Trehan (parthendo@geu.ac.in)

Please feel free to drop an e-mail for any suggestions and ideas.
