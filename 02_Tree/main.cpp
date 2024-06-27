#include <iostream>
#include <01_tree_2.hpp>

int main(int argc, char **argv)
{
	std::cout << "!!testing begining!! " << std::endl;

	BiTree::CreateBinTree_PreOrder();

	std::cout << "!!testing end!!" << std::endl;

	return 0;
}