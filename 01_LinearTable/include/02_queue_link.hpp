#include <iostream>

using namespace std;

#define MAXCAPACITY 10

struct node
{
    node *left;
    node *right;
    int val;
};

class queueLink
{
public:
    static void init_node();
    static void add_left(int key);
    static void add_right(int key);
    static void delete_left();
    static void delete_right();
    static void show();
    static void my_link();

    // private:
    static node *head;
    static node *tail;
    // // static node *link;
    static int size;
};

// Define static members
node *queueLink::head = nullptr;
node *queueLink::tail = nullptr;
int queueLink::size = 0;

// 初始化结点  和链表
void queueLink::init_node()
{
    head = new node;
    tail = new node;
    head->right = tail;
    tail->left = head;
    head->left = nullptr;
    tail->right = nullptr;
}

//  左插
void queueLink::add_left(int key)
{
    if (size == MAXCAPACITY)
    {
        cout << "link full!!" << endl;
        return;
    }
    node *newNode = new node;
    newNode->val = key;
    newNode->right = head->right;
    newNode->left = head;
    head->right = newNode;
    newNode->right->left = newNode;
    size++;
}

//  右差
void queueLink::add_right(int key)
{
    if (size == MAXCAPACITY)
    {
        cout << "link full!!" << endl;
        return;
    }
    node *newNode = new node;
    newNode->val = key;
    newNode->right = tail;
    newNode->left = tail->left;
    newNode->left->right = newNode;
    tail->left = newNode;
    size++;
}

// 左删
void queueLink::delete_left()
{
    if (size == 0)
    {
        cout << "link is empty!!!" << endl;
        return;
    }
    node *freeNode = head->right;
    head->right = freeNode->right;
    freeNode->right->left = head;
    size--;
    delete freeNode;
}

// 右删
void queueLink::delete_right()
{
    if (size == 0)
    {
        cout << "link is empty!!!" << endl;
        return;
    }
    node *freeNode = tail->left;
    freeNode->left->right = tail;
    tail->left = freeNode->left;
    size--;
    delete freeNode;
}

void queueLink::show()
{
    if (size == 0)
    {
        cout << "link is empty!!" << endl;
        return;
    }
    node *current = head->right; // Use a temporary pointer
    while (current != tail)
    {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;
}

// 测试用例
void queueLink::my_link()
{
    queueLink::init_node();
    queueLink::add_right(1);
    queueLink::add_left(2);
    queueLink::add_right(3);
    queueLink::add_left(4);
    queueLink::add_right(5);
    queueLink::add_left(6);
    queueLink::show();
    queueLink::delete_right();
    queueLink::delete_left();
    queueLink::show();
    queueLink::delete_right();
    queueLink::delete_left();
    queueLink::delete_right();
    queueLink::delete_left();
    queueLink::show();
}