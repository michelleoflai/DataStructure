#include <iostream>
#include <01_tree_2.hpp>
#include <02_BS_tree.hpp>

int main(int argc, char **argv)
{
	std::cout << "!!testing begining!! " << std::endl;

	// BiTree::CreateBinTree_PreOrder();
	// BiTree::create_recursion_test();
	BST::creat_BST();

	std::cout << "!!testing end!!" << std::endl;

	return 0;
}