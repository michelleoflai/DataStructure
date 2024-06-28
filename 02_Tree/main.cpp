#include <iostream>
#include <01_tree_2.hpp>
#include <02_BST_create.hpp>
#include<02_BST_search.hpp>
#include<02_BST_delete.hpp>

int main(int argc, char **argv)
{
	std::cout << "---->testing begin<----" << std::endl;

	// BiTree::CreateBinTree_PreOrder();
	// BiTree::create_recursion_test();
	// BSTcreate::creat_BST();
	// BSTsearch::BST_search();
	BSTdelete::BST_delete();

	std::cout << "---->testing end<----" << std::endl;

	return 0;
}