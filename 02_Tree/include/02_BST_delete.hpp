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

struct tree
{
    int data;
    tree *left;
    tree *right;
};

class BSTdelete
{
public:
    // 插入
    static void insert(tree *&T, int data)
    {
        if (T == nullptr)
        {
            tree *node = new tree;
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
    // 中序遍历
    static void print_mid(tree *T)
    {
        if (T == NULL)
        {
            return;
        }
        print_mid(T->left);
        cout << T->data;
        print_mid(T->right);
    }
    // 创建BST
    static tree *create()
    {
        // createTree

        tree *T = nullptr;
        int data[] = {5, 2, 4, 1, 8, 6, 7, 9, 0, 3};
        for (int i = 0; i < 10; i++)
        {
            insert(T, data[i]);
        }
        cout << endl;

        //  print   input 5241867903
        print_mid(T); // successfully -> 0123456789
        cout << endl;
        return T;
    }
    // 删除节点
    static tree *BST_delete(tree *&T, int val)
    {
        if (T == NULL)
            return nullptr;
        if (val < T->data)
        {
            T->left = BST_delete(T->left, val);
        }
        else if (val > T->data)
        {
            T->right = BST_delete(T->right, val);
        }
        else if (val == T->data)
        {
            if (T->left == nullptr && T->right == nullptr)
            {
                tree *temp = T;
                delete T;
                temp = nullptr;
                return temp;
            }
            else if (T->left != nullptr && T->right == nullptr)
            {
                tree *temp = T->left;
                delete T;
                return temp;
            }
            else if (T->left == nullptr && T->right != nullptr)
            {
                tree *temp = T->right;
                delete T;
                return temp;
            }
            else if (T->left != nullptr && T->right != nullptr)
            {
                // 法一：右子树放到左子树上，找到左子树的最大的节点，将右子树放最大节点的右边
                tree *cur = T->left;
                while (cur->right != nullptr)
                {
                    cur = cur->right;
                }
                cur->right = T->right;
                tree *temp = T->left;
                delete T;
                return temp;

                // 法二：左子树放到右子树上，找到右子树的最小的节点，将左子树放最大节点的左边
                // 略；
            }
        }
        return T;
    }

    // 实现BST删除节点
    static void BST_delete()
    {
        // create tree
        tree *T = create();
        T = BST_delete(T, 5);
        print_mid(T); // successfully -> 0123456789
        cout << endl;
    }
};