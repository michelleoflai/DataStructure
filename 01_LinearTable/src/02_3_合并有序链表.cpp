/**
 * 合并俩有序链表，且合并后仍然有序
 */
#include <time.h>
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
    void InserTail(int val)
    {
        Node *p = head_;
        while (p->next_ != nullptr) // O(n)
        {
            p = p->next_;
        }
        p->next_ = new Node(val);
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
    friend void MergeLink(Clink &link1, Clink &link2);

private:
    Node *head_;
};
void MergeLink(Clink &link1, Clink &link2)
{
    Node *l1 = link1.head_->next_;
    Node *l2 = link2.head_->next_;
    Node *last = link1.head_;
    // link1.head_->next_ == nullptr;
    // link2.head_->next_ == nullptr;
    while (l2 != nullptr && l1 != nullptr)
    {
        if (l1->data_ < l2->data_)
        {
            last->next_ = l1;
            last = l1;
            l1 = l1->next_;
        }
        else
        {
            last->next_ = l2;
            last = l2;
            l2 = l2->next_;
        }
    }
    last->next_ = (l1 != nullptr) ? l1 : l2;
}

void main02_3()
{
    Clink l1;
    Clink l2;
    int arr1[] = {1,3,5,56,87};
    int arr2[] = {2,6,32,68};
    for (int v : arr1)
    {
        l1.InserTail(v);
    }
    for (int v : arr2)
    {
        l2.InserTail(v);
    }
    l1.show();
    l2.show();
    MergeLink(l1, l2);
    l1.show();
    // l2.show();
}