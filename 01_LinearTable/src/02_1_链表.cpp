/**
 * 链表
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
    void InserTail(int val)
    {
        Node *p = head_;
        while (p->next_ != nullptr) // O(n)
        {
            p = p->next_;
        }
        p->next_ = new Node(val);
    }
    void InserHead(int val) // O(1)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        head_->next_ = node;
    }
    void Remove(int val)
    {
        Node *q = head_;
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                return;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }
    void Removeall(int val)
    {
        Node *q = head_;
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                q->next_ = p->next_;
                delete p;
                p = q->next_;
            }
            else
            {
                q = p;
                p = p->next_;
            }
        }
    }

    // O(n)
    bool Find(int val)
    {
        Node *p = head_->next_;
        while (p != nullptr)
        {
            if (p->data_ == val)
            {
                return true;
            }
            else
            {
                p = p->next_;
            }
        }
        return false;
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

private:
    Node *head_;
};

void main02()
{
    Clink link;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        link.InserHead(rand() % 100 + 1);
    }
    // link.show();

    Clink link2;
    for (int i = 0; i < 10; i++)
    {
        link2.InserTail(rand() % 10 + 45);
    }
    // link2.show();

    link.InserTail(200);
    // link.show();
    link.Remove(200);
    // link.show();

    Clink link3;
    link3.InserTail(45);
    link3.InserTail(14);
    link3.InserTail(32);
    link3.InserTail(62);
    link3.InserTail(45);
    link3.show();
    link3.Removeall(45);
    link3.show();
}