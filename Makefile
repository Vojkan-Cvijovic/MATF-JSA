CC=g++
CFLAGS= -std=c++11

analizator: lex.yy.o parser.tab.o SymbolTable.o MethodTable.o ClassTable.o ClassDef.o
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
ClassTable.o: ClassTable.cpp ClassTable.hpp ClassDef.hpp
	$(CC) $(CFLAGS) -c -o $@ $<
ClassDef.o: ClassDef.cpp ClassDef.hpp FieldType.hpp Type.hpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *~ *tab* lex.yy.* *.o analizator *.output
