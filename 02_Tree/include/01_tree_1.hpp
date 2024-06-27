#include <iostream>

/**
 * 二叉树
 */

using namespace std;

template <typename T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *leftChild, *rightChild;
    BinTreeNode():leftChild(NULL),rightChild(NULL){}
    BinTreeNode(T x,BinTreeNode<T> *l=NULL,BinTreeNode<T> *r = NULL):data(x),leftChild(l),rightChild(r){}
};

template <typename T>
class BinaryTree
{
public:
    //构造函数
    BinaryTree() : root(NULL) {}
    //指定结束标志的构造函数
    BinaryTree(T value) : root(NULL), RefValue(value) {}
    //析构函数
    ~BinaryTree();
    //拷贝构造函数，拷贝二叉树(前序遍历的应用)
    BinaryTree(BinaryTree<T> &s);

    //使用广义表创建二叉树，以'#'字符代表结束
    static void CreateBinTree(){    }
     //前序遍历创建二叉树(前序遍历的应用)，用#表示空结点
    static void CreateBinTree_PreOrder();
     //使用先序遍历和中序遍历创建二叉树
    static void CreateBinTreeBy_Pre_In(const char *pre, const char *in);
     //使用后序遍历和中序遍历创建二叉树
    static void CreateBinTreeBy_Post_In(const char *post, const char *in);
 
     //先序遍历（递归）
    static void PreOrder();
     //中序遍历(递归)
    static void InOrder();
     //后序遍历（递归）
    static void PostOrder();
     //先序遍历(非递归1)
    static void PreOrder_NoRecurve1();
     //先序遍历(非递归2)
    static void PreOrder_NoRecurve2();
     //中序遍历(非递归)
    static void InOrder_NoRecurve();
     //后序遍历(非递归)
    static void PostOrder_NoRecurve();
     //层次遍历(非递归)
    static void LevelOrder();

     //获取二叉树的根节点
    static BinTreeNode<T> *getRoot();
     //获取current结点的父节点
    static BinTreeNode<T> *Parent(BinTreeNode<T> *current);
     //获取current结点的左结点
    static BinTreeNode<T> *LeftChild(BinTreeNode<T> *current);
     //获取current结点的右结点
    static BinTreeNode<T> *RightChild(BinTreeNode<T> *current);

     //销毁函数
    static void Destroy();
     //判断两颗二叉树是否相等(前序遍历的应用)
    static bool operator==(BinaryTree<T> &s);
     //计算二叉树的结点的个数(后序遍历的应用)
    static int Size();
     //计算二叉树的高度（后序遍历的应用）
    static int Height();
     //判断二叉树是否为空
    static bool Empty();
     //以广义表的形式输出二叉树(前序遍历的应用)
    static void PrintBinTree();
     //翻转二叉树
    static void InvertTree();
 
private:
    static BinTreeNode<T> *root; //根节点
    T RefValue;           //数据输入停止的标志，需要一个构造函数
};
