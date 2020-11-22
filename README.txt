An elaborate explanation of the testcases and the code is provided in documentation.txt

Directories
------------

"src" directory contains the code, the executable "emulator" and the sample assembly language code i.e. bubblesort.asm and addtwonumbers.asm

To rebuild the code or compilation
**************************************************************************************************
$ sudo apt-get install clang++	//install clang++
$ make					//rebuild the code
$ make clean				//delete the object files created in the process of rebuild
**************************************************************************************************

To execute the 8085-Emulator
**************************************************************************************************
$ ./emulator 				//to run the emulator on terminal
$ ./emulator addtwonumbers.asm	//to run the emulator with an assembly level file
$ ./emulator --debugger		//to enable debugger
**************************************************************************************************

Various modes of emulator and debugger are described in the documentation and the screenshots are available in the screenshot folder.

"test" directory consists the executable file "runTests" that can be used to execute unit testing on the code base, it also contains tests.cpp where the testcases are defined and the Google Test Framework required for installation and execution of tests inside the GTest folder.
**************************************************************************************************
$ cd test/GTest\ Framework/	// toggle to the GTest or the google test framework directory
$ cd ..			// toggles back to the test directory
$ cmake CMakeLists.txt		// generates the makefile for running test
$ make				// builds the executable for testing
$ ./runTests			// performs using testing
**************************************************************************************************

"screenshot" directory contains screenshots of different test ran on the codebase along with the emulator in action.

Individual Contribution:
Parth Trehan(MT2019074)

Mohit Bansal(MT2019065)

