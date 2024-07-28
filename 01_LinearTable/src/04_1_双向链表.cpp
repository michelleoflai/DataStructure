#include <iostream>
using namespace std;

// 定义双向链表
struct Node
{
    Node(int data = 0)
        : data_(data), next_(nullptr), pre_(nullptr) {}
    int data_;
    Node *next_;
    Node *pre_;
};

class DoubleLink
{
public:
    DoubleLink()
    {
        head_ = new Node();
    }
    ~DoubleLink()
    {
        Node *p = head_;
        while (p != nullptr)
        {
            head_ = head_->next_;
            delete p;
            p = head_;
        }
    }

public:
    void InserHead(int val)
    {
        Node *node = new Node(val);
        node->next_ = head_->next_;
        node->pre_ = head_;
        if (head_->next_ != nullptr)
        {
            head_->next_->pre_ = node;
        }

        head_->next_ = node;
    }

    void InserTail(int val){
        Node* node=new Node(val);
        Node* p=head_;
        while (p->next_!=head_)
        {
            p=p->next_;
        }
        p->next_=node;
        node->pre_=p;
        
    }

private:
    Node *head_;
};

void main4_1()
{
}
