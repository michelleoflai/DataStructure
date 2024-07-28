#include <iostream>
#include <string>
using namespace std;

// 适配器 queue - push pop front back empty size
class Queue
{
public:
    Queue(int size = 10) : cap_(size), front_(0), rear_(0)
    {
        pQue_ = new int[cap_];
    }
    ~Queue()
    {
        delete[] pQue_;
        pQue_ = nullptr;
    }

public:
    void push(int val)
    {
        if (((rear_ + 1) % cap_) == front_)
        {
            expand(2 * cap_);
        }
        pQue_[rear_] = val;
        rear_ = (rear_ + 1) % cap_;
        size_++;
    }
    void pop()
    {
        if (this->empty())
        {
            printf("queue is empty");
        }
        front_ = (front_ + 1) % cap_;
        size_--;
    }
    int front() const
    {
        if (this->empty())
        {
            perror("empty");
        }
        return front_;
    }
    int back() // 注意：rear_指向的是末尾元素的后一个位置；
    {
        if (this->empty())
        {
            perror("empty");
        }
        return pQue_[(rear_ - 1 + cap_) % cap_];
    }
    bool empty() const
    {
        return front_ == rear_ ? true : false;
    }
    int size() const
    {
        return size_;
    }

private:
    void expand(int size)
    {
        int *p = new int[size];
        int i = 0;
        int j = front_;
        while (j != rear_)
        {
            p[i++] = pQue_[j];
            j = (j + 1) % cap_;
        }
        cap_ = size;
        front_ = 0;
        rear_ = i;
        delete[] pQue_;
        pQue_ = p;
   }

private:
    int *pQue_;
    int cap_; // 空间容量
    int front_;
    int rear_;
    int size_;
};

void main08_1()
{
}