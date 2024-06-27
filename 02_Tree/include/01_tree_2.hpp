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
};