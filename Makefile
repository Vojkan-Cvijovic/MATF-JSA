CC=g++
CFLAGS=-Wall -std=c++11

analizator: lex.yy.o parser.tab.o SymbolTable.o MethodTable.o ClassTable.o ClassDefinition.o
	$(CC) $(CFLAGS) -o $@ $^
parser.tab.o: parser.tab.cpp parser.tab.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v $<
lex.yy.o: lex.yy.c parser.tab.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
lex.yy.c: lexer.lex
	flex $<
SymbolTable.o: SymbolTable.cpp SymbolTable.hpp Type.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
MethodTable.o: MethodTable.cpp MethodTable.hpp Type.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
ClassTable.o: ClassTable.cpp ClassTable.hpp ClassDefinition.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
ClassDefinition.o: ClassDefinition.cpp ClassDefinition.hpp FiledType.hpp Type.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *~ *tab* lex.yy.* *.o pseudokod *.output