IDIR = ./header
CC = clang++
CFLAGS=-I$(IDIR)

ODIR=object
LDIR=./src

LIBS=-lm

_DEPS = MASTER.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  validityAddress.o validityHexadecimal.o LDA.o complement.o decimalToHex.o hexToDecimal.o hexAdd.o hexAdd16bit.o hexSub.o hexSub16bit.o increaseAddress.o operationSize.o registerNumber.o validityData.o validityRegisterPair.o validityRegisters.o validityFile.o LHLD.o LXI.o MOV.o MVI.o SET.o SHLD.o STA.o STAX.o XCHG.o CMA.o CMP.o JC.o JMP.o JNC.o JNZ.o JZ.o ADD.o ADI.o DAD.o DCR.o DCX.o INR.o INX.o SUB.o SUI.o  execution.o executionPhase.o updatedAddress.o main.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
	
emulator: $(OBJ)
	clang++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
