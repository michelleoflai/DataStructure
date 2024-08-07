/**
 * 反转链表
 * 思路：
 *      1、定义指针p指向head_->next;
 *      2、将head_的地址域制空，相当于一个空链表(head_>next=nullptr)
 *      3、把p指针指向的节点，头插法，依次插入新的空链表中；
 * 关键：头插法；
 */

/**
 * 倒数第k个指针  -> 快慢指针
 *
 */
#include <iostream>
using namespace std;

struct Node
{
    int data_;
    Node *next_;
    Node(int data = 0) : data_(data), next_(nullptr) {}
};

class Clink
{
public:
    Clink()
    {
        head_ = new Node();
    }
    ~Clink()
    {
        Node *p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
        head_ = nullptr;
    }

public:
    void InserHead(int val) // O(1)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
    }

    void Reverse()
    {
        Node *p = head_->next_;
        head_->next_ = nullptr;
        if (p == nullptr)
        {
            return;
        }
        while (p != nullptr)
        {
            Node *q = p->next_;

            p->next_ = head_->next_;
            head_->next_ = p;

            p = q;
        }
    }

    void show()
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            cout << p->data_ << " ";
            p = p->next_;
        }
        cout << endl;
    }
    friend bool GetLastNode(Clink &link, int k, int &val);
    friend void MergeLink(Clink &link1, Clink &link2);

private:
    Node *head_;
};

bool GetLastNode(Clink &link, int k, int &val)
{
    Node *l = link.head_;
    Node *r = l;

    for (int i = 0; i < k; i++)
    {
        r = r->next_;
        if (r == nullptr && i != k - 1)
        {
            printf("fail long \n\n");
            return false;
        }
    }

    while (r != nullptr)
    {
        r = r->next_;
        l = l->next_;
    }
    val = l->data_;
    return true;
}

void main02_2()
{
    Clink link;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        link.InserHead(rand() % 100 + 1);
    }
    link.show();
    link.Reverse();
    link.show();
    int val;
    if (GetLastNode(link, 11, val))
    {
        cout << "delete: " << val << endl;
    }
    link.show();
}