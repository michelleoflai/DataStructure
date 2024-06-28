#include <iostream>

/**
 * binary search tree 二叉搜索树    // binary sort tree 二叉排序树
 */

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
public:
    // 插入节点
    static void insert(Node *&T, int data)
    {
        if (T == nullptr)
        {
            Node *node = new Node;
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
    static void print_mid(Node *T)
    {
        if (T == NULL)
        {
            return;
        }
        print_mid(T->left);
        cout << T->data;
        print_mid(T->right);
    }

    // 创建BST 并实例
    static void creat_BST()
    {
        Node *T = nullptr;
        int data;
        for (int i = 0; i < 10; i++)
        {
            cout << "input: ";
            cin >> data;
            insert(T, data);
        }
        cout << endl;

        //  print
        print_mid(T);
        cout << endl;
    }
};
