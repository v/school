/**********************************************
        CS415  Compilers Project3  
            Spring 2011
**********************************************/

#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#define NOLABEL -1
#define EMPTY 0
#define STATIC_AREA_ADDRESS 1024

typedef enum opcode_name {NOP=0, VECTON, VECTOFF, ADD, SUB, MULT,
			  L_AND, L_OR, L_XOR,
	                  LOADI, LOAD, LOADAI, LOADAO, 
                          STORE, STOREAI, STOREAO, 
			  BR, CBR, CMPLT, CMPLE, CMPEQ, CMPNE,
			  I2I,OUTPUT} Opcode_Name;
extern 
FILE *outfile;

extern
int NextRegister();

extern
int NextLabel();

extern
int NextOffset();

extern
void emitComment(char *comment);

extern 
void emit(int label_index, 
	  Opcode_Name opcode, 
	  int field1, 
	  int field2, 
	  int field3);


#endif /* _INSTRUCTION_H_ */




