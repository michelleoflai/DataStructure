#include <iostream>

/**
 * 二叉树 简单
 */

using namespace std;

struct biTree
{
    int val;
    biTree *left;
    biTree *right;
};

class BiTree
{
public:
    // 先须打印二叉树
    static void Print_PreOrder(biTree *tree)
    {
        if (tree == NULL)
        {
            return;
        }
        cout << tree->val;
        Print_PreOrder(tree->left);
        Print_PreOrder(tree->right);
    }

    // 中序
    static void Print_InOrder(biTree *tree){
        if (tree == NULL)
        {
            return;
        }
        Print_PreOrder(tree->left);
        cout << tree->val;
        Print_PreOrder(tree->right);
    }

    //  无递归创建 简单
    static void CreateBinTree_PreOrder()
    {
        // A(B(D,E),C(,))
        biTree *D = new biTree;
        D->left = nullptr;
        D->right = nullptr;
        D->val = 5;

        biTree *E = new biTree;
        E->left = nullptr;
        E->right = nullptr;
        E->val = 8;

        biTree *B = new biTree;
        B->left = D;
        B->right = E;
        B->val = 3;

        biTree *C = new biTree;
        C->left = nullptr;
        C->right = nullptr;
        C->val = 2;

        biTree *A = new biTree;
        A->left = B;
        A->right = C;
        A->val = 1;

        Print_PreOrder(A); // succesfully -> 13582
        cout << endl;
    }

    // 递归 先序 创建
    static void create_recursion(biTree *&T)
    {
        // A(B(D,E),C(,))  13500800200
        int num;
        cout << " input current num (0 for null): ";
        cin >> num;
        if (num == 0)
        {
            return;
        }
        biTree *node = new biTree;
        node->val = num;
        T = node;
        create_recursion(T->left);
        create_recursion(T->right);
    }

    // 递归 先序 创建 实现
    static void create_recursion_test(){
        biTree* T = new biTree;
        create_recursion(T);
        
        Print_PreOrder(T); // succesfully -> 13582

        Print_InOrder(T);

        cout << endl;
    }

};