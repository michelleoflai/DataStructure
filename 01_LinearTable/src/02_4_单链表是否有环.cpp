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

bool IsLinkHasCircle(Node *head, int &val)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != nullptr && fast->next_ != nullptr)
    {
        fast = fast->next_->next_;
        slow = slow->next_;
        if (slow == fast){
            /* 遇见后判断入口:一个指针（fast）从头结点开始走，另一个（slow）从相遇的地方开始走，再次遇见的节点为入口 */
            fast=head;
            while (slow!=fast)
            {
                slow=slow->next_;
                fast=fast->next_;
            }
            val=fast->data_;
            return true;
        }
    }
    return false;
}

void main2_4()
{
    Node head;
    Node n1(1),n2(2),n3(3),n4(4);
    head.next_=&n1;
    n1.next_=&n2;
    n2.next_=&n3;
    n3.next_=&n4;
    n4.next_=&n1;
    int val;
    if(IsLinkHasCircle(&head,val)){
        cout<<"yes jiedian : "<< val <<endl;
    }else{
        cout<<"no"<<endl;
    }
}