#include <iostream>
#include "include/01_myStack.hpp"
// #include "include/02_queue_link.hpp"

void my_stack()
{
	Stack S;
	// myStack::ush(S, 1);
	myStack::Push(S, 8);
	myStack::Push(S, 5);
	myStack::Push(S, 4);
	myStack::Push(S, 2);
	myStack::show(S);
	myStack::Pop(S);
	myStack::show(S);
	myStack::delete_index(S, 2);
	myStack::delete_index(S, 5);
	myStack::show(S);
}


int main(int argc, char **argv)
{
	std::cout << "testing string! " << std::endl;

	my_stack();
	// queueLink::my_link();

	return 0;
}