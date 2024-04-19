#ifndef  __STACK_H__
#define  __STACK_H__

#include <iostream>
#include <ctype.h>  
#include <stdlib.h> 
using namespace std;

#define STACK_SIZE 100

// infix to postfix, when T == int
// evaluation of postfix when T == float
template <class T>
class Stack { 
	private: 
		T stack[STACK_SIZE];
        int max_size;
		int top;
	public: 
		Stack() { top = -1; max_size = STACK_SIZE;}
		void push(T value) { stack[++top] = value; } // assuming 'not full'
		T pop() { return stack[top--]; }   
		int isEmpty() { return top == -1; }
		T read_top() { return stack[top]; }  
};

#endif
