/**
 * 约瑟夫环问题
 * 从第k个人开始报数，每次报m个，出列，下一个继续从1开始报到m。
 */

#include <iostream>
using namespace std;
struct Node
{
    int data_;
    Node *next_;
    Node(int val = 0, Node *next = nullptr) : data_(val), next_(next) {}
};

void Joseph(Node *head, int k, int m)
{
    Node *p = head;
    Node *q = head;
    while (q->next_!=head)
    {
        q = q->next_;
    }
    for (int i = 0; i < k - 1; i++)
    {
        q = q->next_;
    }
    p = q->next_;

    while (1)
    {
        for (int i = 0; i < m - 1; i++)
        {
            q = q->next_;
        }
        p = q->next_;
        q->next_ = p->next_;
        cout << p->data_ << " ";
        delete p;
        p = q->next_;
        if (p == q)
        {
            cout << p->data_ << " ";
            delete p;
            p = q = nullptr;
            break;
        }
    }
}

void main2_6()
{
    // Node head;  // 特别注意：这句是在堆上的，但是delete p是在栈上
    // Node *head = new Node(0); // 无头循环链表
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    n1->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;
    n5->next_ = n6;
    n6->next_ = n7;
    n7->next_ = n1;
    Joseph(n1, 1, 1);
}
