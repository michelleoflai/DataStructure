#include <iostream>
// #include <02_BST_create.hpp>

/**
 * BST查找
 * binary search tree 二叉搜索树
 * or
 * binary sort tree 二叉排序树
 *
 * from:BV1gu411A791
 */

using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

class BSTsearch
{
public:
    // 查找1 递归
    static treeNode *search(treeNode *T, int target)
    {
        if (T == nullptr)
            return NULL;

        else if (target < T->data)
            return search(T->left, target);

        else if (target > T->data)
            return search(T->right, target);

        if (target == T->data)
            return T;

        return NULL;
    }

    // 查找2 迭代
    static treeNode *search_tree(treeNode *T, int target)
    {
        treeNode *cur = T;
        while (cur != NULL)
        {
            if (target < cur->data)
            {
                cur = cur->left;
            }
            else if (target > cur->data)
            {
                cur = cur->right;
            }
            else if (cur->data == target)
            {
                return cur;
            }
        }
        return cur;
    }

    // 插入
    static void insert(treeNode *&T, int data)
    {
        if (T == nullptr)
        {
            treeNode *node = new treeNode;
            node->data = data;
            node->left = nullptr;
            node->right = nullptr;
            T = node;
        }
        else
        {
            if (data < T->data)
            {
                insert(T->left, data);
            }
            else
            {
                insert(T->right, data);
            }
        }
    }

    // 中序打印
    static void print_mid(treeNode *T)
    {
        if (T == NULL)
        {
            return;
        }
        print_mid(T->left);
        cout << T->data;
        print_mid(T->right);
    }

    static void BST_search()
    {
        // createTree

        treeNode *T = nullptr;
        int data[] = {5, 2, 4, 1, 8, 6, 7, 9, 0, 3};
        for (int i = 0; i < 10; i++)
        {
            // cout << "input: ";
            // cin >> data;
            insert(T, data[i]);
        }
        cout << endl;

        //  print   input 5241867903
        print_mid(T); // successfully -> 0123456789
        cout << endl;

        // testing
        cout << "search for number: ";
        int target;
        cin >> target;
        treeNode *node = search_tree(T, target);
        if (node == NULL)
            cout << "empty!!" << endl;
        else
            cout << "the target is : " << node->data << endl;
    }
};