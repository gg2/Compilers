/* 
 * stack_test.cpp
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * 2015 Apr 2
 * gibl3465@vandals.uidaho.edu
 *
 * Program to test interface for stack
 *------------------------------------
 */

#include<iostream>
#include<cstdlib>

#include"stack.cpp"

void ZipList(Stack,Stack,Stack*);
void DeleteNegs(Stack*);
void TestStack(int,int);
void TestZip(int,int,int,int);
void TestDeleteNegs(int,int);

int main()
{
	std::cout << "\nCS121, Lab 9 - Gabe Gibler\n" << std::endl;
	std::cout << "Stack Test\n" << std::endl;
	TestStack(0,0);
	TestStack(1,1);
	TestStack(0,1);
	TestStack(-1,0);
	TestStack(-50,50);

	std::cout << "List Zipping\n" << std::endl;	
	TestZip(0,0,0,0);
	TestZip(1,4,1,4);
	TestZip(3,10,-3,3);
	TestZip(0,20,0,0);
	TestZip(0,0,-20,1);
	TestZip(-1000,1000,1000,-1000);

	std::cout << "Deleting Negatives\n" << std::endl;
	TestDeleteNegs(0,0);
	TestDeleteNegs(0,1);
	TestDeleteNegs(-1,0);
	TestDeleteNegs(0,100);
	TestDeleteNegs(-100,1);
	TestDeleteNegs(-100,100);
	
	// Exit program
	return 0;
}

void TestStack(int m, int n) {
	Stack S;
	int i = 0;
	
	std::cout << "Stack created ... \n";
	std::cout << "Stack.size(): " << S.size() << "\n";
	std::cout << "Stack.top(): " << S.top() << "\n";
	std::cout << "Stack contents: ";
	S.print();
	std::cout << "Pushing " << n-m << " values onto stack ... \n";
	for (int i=m; i<n; i++) {
		S.push(i);
	}
	std::cout << "Stack.size(): " << S.size() << "\n";
	std::cout << "Stack.top(): " << S.top() << "\n";
	std::cout << "Stack contents: ";
	S.print();
	std::cout << std::endl << "Popping values from stack ... \n";
	for (int i=m; i<n; i++) {
		std::cout << S.pop() << " ";
	}
	std::cout << std::endl;
	std::cout << "Stack.size(): " << S.size() << "\n";
	std::cout << "Stack contents: ";
	S.print();
	std::cout << std::endl << "- - - - - - - - - - - - -\n" << std::endl;
}

void ZipList(Stack inA, Stack inB, Stack* out) {
	Stack BRev;
	Stack ZRev;

	// Reverse 2nd list before interleaving, per specifications
	while (inB.size() > 0) {
		BRev.push(inB.pop());
	}
	
	// Handle case of differently-sized lists 
	while (inA.size() > 0 || BRev.size() > 0) {
		// Interleave next value in A
		if (inA.size() > 0) {
			ZRev.push(inA.pop());
		}
		// Interleave next value in B
		if (BRev.size() > 0) {
			ZRev.push(BRev.pop());
		}
	}
	// Reverse interleaved values so they print per specifications
	while (ZRev.size() > 0) {
		out->push(ZRev.pop());
	}
}

void TestZip(int m, int n, int o, int p) {
	Stack A;
	Stack B;
	Stack* Z = new Stack;
	int i = 0;
	
	std::cout << "Preparing lists ...\n";
	for (i=n; i>m; i--) {
		A.push(i);
	}
	std::cout << "\nList A prepared. \n";
	A.print();
	std::cout << std::endl;
	for (i=p; i>o; i--) {
		B.push(i);
	}
	std::cout << "\nList B prepared. \n";
	B.print();
	std::cout << std::endl;
	
	ZipList(A,B,Z);
	std::cout << "And the zipped result of A and B is ...\n{ ";
	Z->print();
	std::cout << "} \n" << "- - - - - - - - - - - - -\n" << std::endl;
	delete Z;
}

void DeleteNegs(Stack* N) {
	Stack* P = new Stack;
	
	while (N->size() > 0) {
		if (N->top() < 0) {
			N->pop();
		} else {
			P->push(N->pop());
		}
	}
	while (P->size() > 0) {
		N->push(P->pop());
	}
	delete P;
}

void TestDeleteNegs(int m, int n) {
	Stack* S = new Stack;
	int i;
	
	for (i=m; i<n; i++) {
		if (i%2 == 0)
			S->push(i);
		else
			S->push(-1*i);
	}

	std::cout << "List 1 with negatives: \n";
	S->print();
	std::cout << std::endl;
	DeleteNegs(S);
	std::cout << "List 1 sans negatives: \n";
	S->print();
	std::cout << std::endl;
	while (S->size() > 0) {
		S->pop();
	}
	
	for (i=m; i<n; i++) {
		if (i%3 == 0 && i<(n/2))
			S->push(-1*i);
		else
			S->push(i);
	}

	std::cout << "List 2 with negatives: \n";
	S->print();
	std::cout << std::endl;
	DeleteNegs(S);
	std::cout << "List 2 sans negatives: \n";
	S->print();
	std::cout << std::endl << "- - - - - - - - - - - - -\n" << std::endl;
	while (S->size() > 0) {
		S->pop();
	}
	delete S;
}