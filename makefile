CC=gcc
CFLAGS=-c -g

120++: 120++.o semantics.o 120++parse.tab.o lex.yy.o scopes.o symbols.o parse_tree.o types.o stack.o
	$(CC) -o 120++ 120++.o semantics.o 120++parse.tab.o lex.yy.o scopes.o symbols.o parse_tree.o types.o stack.o

120++.o: 120++.c 120++.h globals.h scopes.c scopes.h symbols.c symbols.h parse_tree.c parse_tree.h types.c types.h stack.c stack.h
	$(CC) $(CFLAGS) 120++.c scopes.c symbols.c parse_tree.c types.c stack.c

semantics.o: semantics.c semantics.h globals.h 120++nonterms.h scopes.c scopes.h symbols.c symbols.h parse_tree.c parse_tree.h types.c types.h stack.c stack.h
	$(CC) $(CFLAGS) semantics.c scopes.c symbols.c parse_tree.c types.c stack.c

120++parse.tab.o: 120++parse.tab.c lex.yy.c globals.h symbols.c symbols.h parse_tree.c parse_tree.h types.c types.h stack.c stack.h
	$(CC) $(CFLAGS) 120++parse.tab.c lex.yy.c parse_tree.c types.c symbols.c stack.c

120++parse.tab.c 120++parse.tab.h: 120++parse.y 120++nonterms.h
	bison -d -v 120++parse.y

lex.yy.o: lex.yy.c globals.h 120++parse.tab.h symbols.c symbols.h parse_tree.c parse_tree.h types.c types.h stack.c stack.h
	$(CC) $(CFLAGS) lex.yy.c parse_tree.c types.c symbols.c stack.c

lex.yy.c: 120++lex.l 120++parse.tab.h
	flex 120++lex.l

scopes.o: scopes.c scopes.h symbols.c symbols.h parse_tree.c parse_tree.h types.c types.h
	$(CC) $(CFLAGS) scopes.c symbols.c parse_tree.c types.c

symbols.o: symbols.c symbols.h parse_tree.c parse_tree.h types.c types.h
	$(CC) $(CFLAGS) symbols.c parse_tree.c types.c

parse_tree.o: parse_tree.c parse_tree.h
	$(CC) $(CFLAGS) parse_tree.c

type.o: types.c types.h
	$(CC) $(CFLAGS) types.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c

test: test.c test.h globals.h parse_tree.c parse_tree.h 120++defs.h symbols.c symbols.h stack.c stack.h
	$(CC) -g test.c parse_tree.c symbols.c stack.c -o test.exe
