#include <iostream>
#include "include/01_myStack.hpp"
#include "include/02_queue_link.hpp"

int main(int argc, char **argv)
{
	std::cout << "!!testing begining!! " << std::endl;

	myStack::my_stack();
	queueLink::my_link();



	std::cout<<"!!testing end!!"<<std::endl;

	return 0;
}