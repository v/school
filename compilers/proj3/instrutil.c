/**********************************************
        CS415 Compilers Project3  
             Spring  2011
**********************************************/

#include <stdio.h>
#include "instrutil.h"
#include <stdlib.h>

static next_register = 1;
static next_label = 0;
static next_offset = -4;

int NextRegister() 
{
  return next_register++;
}

int NextLabel() 
{
  return next_label++;
}

int NextOffset() 
{ next_offset = next_offset + 4;
  return next_offset;
}

void
emitComment(char *comment)
{
  fprintf(outfile, "\t// %s\n", comment);  
}

void
emit(int label_index,
     Opcode_Name opcode, 
     int field1, 
     int field2, 
     int field3) 
{
  char *label = " ";
  
  if (label_index < NOLABEL) {
    printf("ERROR: \"%d\" is an illegal label index.\n", label_index);
    return;
  }
    
  if (label_index > NOLABEL) {
    label = (char *) malloc(100);
    sprintf(label, "L%d:", label_index);
  }

  switch (opcode) {
  case NOP: 
    fprintf(outfile, "%s\t nop \n", label);
    break;
  case VECTON: 
    fprintf(outfile, "%s\t vecton \n", label);
    break;
  case VECTOFF: 
    fprintf(outfile, "%s\t vectoff \n", label);
    break;
  case ADD:
    fprintf(outfile, "%s\t add r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case SUB: 
    fprintf(outfile, "%s\t sub r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case MULT: 
    fprintf(outfile, "%s\t mult r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case L_AND: 
    fprintf(outfile, "%s\t and r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case L_OR: 
    fprintf(outfile, "%s\t or r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case L_XOR: 
    fprintf(outfile, "%s\t xor r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case LOAD: 
    /* Example: load r1 => r1 */
    fprintf(outfile, "%s\t load r%d \t=> r%d \n", label, field1, field2);
    break;
  case LOADI: 
    /* Example: loadI 1024 => r1 */
    fprintf(outfile, "%s\t loadI %d \t=> r%d \n", label, field1, field2);
    break;
  case LOADAI: 
    /* Example: loadAI r1, 16 => r3 */
    fprintf(outfile, "%s\t loadAI r%d, %d \t=> r%d \n", label, field1, field2, field3);
    break;
  case LOADAO: 
    /* Example: loadAO r1, r2 => r3 */
    fprintf(outfile, "%s\t loadAO r%d, r%d \t=> r%d \n", label, field1, field2, field3);
    break;
  case STORE: 
    /* Example: store r1 => r2 */
    fprintf(outfile, "%s\t store r%d \t=> r%d \n", label, field1, field2);
    break;
  case STOREAI: 
    /* Example: storeAI r1 => r2, 16 */
    fprintf(outfile, "%s\t storeAI r%d \t=> r%d, %d \n", label, field1, field2, field3);
    break;
  case STOREAO: 
    /* Example: storeAO r1 => r2, r3 */
    fprintf(outfile, "%s\t storeAO r%d \t=> r%d, r%d \n", label, field1, field2, field3);
    break;
  case BR: 
    /* Example: br L1 */
    fprintf(outfile, "%s\t br L%d\n", label, field1);
    break;
  case CBR: 
    /* Example: cbr r1 => L1, L2 */
    fprintf(outfile, "%s\t cbr r%d \t=> L%d, L%d\n", label, field1, field2, field3);
    break;
  case CMPLT: 
    /* Example: cmp_LT r1, r2 => r3 */
    fprintf(outfile, "%s\t cmp_LT r%d, r%d \t=> r%d\n", label, field1, field2, field3);
    break;
  case CMPLE: 
    /* Example: cmp_LE r1, r2 => r3 */
    fprintf(outfile, "%s\t cmp_LE r%d, r%d \t=> r%d\n", label, field1, field2, field3);
    break;
  case CMPEQ: 
    /* Example: cmp_EQ r1, r2 => r3 */
    fprintf(outfile, "%s\t cmp_EQ r%d, r%d \t=> r%d\n", label, field1, field2, field3);
    break;
  case CMPNE: 
    /* Example: cmp_NE r1, r2 => r3 */
    fprintf(outfile, "%s\t cmp_NE r%d, r%d \t=> r%d\n", label, field1, field2, field3);
    break;
  case I2I: 
    /* Example: i2i r1 => r2 */
    fprintf(outfile, "%s\t i2i r%d \t=> r%d \n", label, field1, field2);
    break;
  case OUTPUT: 
    /* Example: output 1024 */
    fprintf(outfile, "%s\t output %d\n", label, field1);
    break;
  default:
    fprintf(stderr, "Illegal instruction in \"emit\" \n");
  }

}



