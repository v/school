
CC = gcc 
CFLAGS = -g 

OBJs = parse.tab.o symtab.o attr.o lex.yy.o 

default: parser

parser: ${OBJs}
	${CC} ${CFLAGS} ${OBJs} -o parser -lfl

lex.yy.c: scan.l parse.tab.h attr.h
	flex -i scan.l

parse.tab.c: parse.y attr.h symtab.h
	bison -dv parse.y

parse.tab.h: parse.tab.c

clean:
	rm -f parser lex.yy.c *.o parse.tab.[ch] parse.output

depend:
	makedepend -I. *.c

# DO NOT DELETE THIS LINE -- make depend depends on it.
