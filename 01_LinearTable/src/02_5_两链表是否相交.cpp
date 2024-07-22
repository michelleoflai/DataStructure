/**
 * 1 单链表是否有环，且找到环入口
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

bool IsLinkHasMerge(Node *head1, Node *head2, int &val)
{
    Node *p = head1;
    Node *q = head2;
    int cnt1 = 0, cnt2 = 0;
    while (p != nullptr)
    {
        cnt1++;
        p = p->next_;
    }
    while (q != nullptr)
    {
        cnt2++;
        q = q->next_;
    }
    p = head1;
    q = head2;
    if (cnt1 > cnt2)
    {
        int diff = cnt1 - cnt2;
        while (diff)
        {
            p = p->next_;
            diff--;
        }
    }
    else
    {
        int diff = cnt2 - cnt1;
        while (diff)
        {
            q = q->next_;
            diff--;
        }
    }
    while (q != nullptr && p != nullptr)
    {
        if (q == p)
        {
            val = p->data_;
            return true;
        }
        p = p->next_;
        q = q->next_;
    }
    return false;
}

void main2_5()
{
    Node head1;
    Node head2;
    Node n1(1), n2(2), n3(3), n4(4);
    Node m1(5), m2(6), m3(7);
    head1.next_ = &n1;
    n1.next_ = &n2;
    n2.next_ = &n3;
    n3.next_ = &n4;
    head2.next_ = &m1;
    m1.next_ = &m2;
    m2.next_ = &m3;
    m3.next_ = &n3;
    int val = 0;
    if (IsLinkHasMerge(&head1, &head2, val))
    {
        cout << "jiedian: " << val << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}