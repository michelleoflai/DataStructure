/**
 * 栈
 */

#include <iostream>
#include <cstring>
using namespace std;

// 顺序栈 c++适配器 stack   push pop top empty size
class SeqStack
{
public:
    SeqStack(int size = 10) : mtop(0), mcap(size)
    {
        mpStack = new int[mcap];
    }
    ~SeqStack()
    {
        delete[] mpStack;
        mpStack == nullptr;
    }

public:
    void push(int val)
    {
        if (mtop == mcap)
        {
            expand(2 * mcap);
        }
        mpStack[mtop++] = val;
    }
    void pop()
    {
        if (mtop == 0)
        {
            throw "stack is empty!";
        }
        else
        {
            mtop--;
        }
    }
    int top() const
    {
        if (mtop == 0)
        {
            throw "stack is empty";
        }
        else
        {
            return mpStack[mtop - 1];
        }
    }
    bool empty() const
    {
        if (mtop == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return mtop;
    }

private:
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, mpStack, mtop * sizeof(int));
        delete[] mpStack;
        mpStack = p;
        mcap = size;
    }

public:
    int *mpStack;
    int mtop;
    int mcap;
};

void main06_1()
{
}