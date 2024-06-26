#include <iostream>

using namespace std;

#define MAXVERTICES 20

struct Stack
{
    int Stacklist[MAXVERTICES] = {0}; // 初始化栈中元素
    int top = -1;                     // 初始化指针位置
};

class myStack
{
public:
    static void Push(Stack &S, int key);
    static int Pop(Stack &S);
    static void delete_index(Stack &S, int key);
    static int find(Stack &S, int key);
    static void show(Stack &S);
    static void my_stack();

private:
    static Stack S;
};

// 入栈
void myStack::Push(Stack &S, int key)
{
    if (S.top == MAXVERTICES - 1)
    {
        cout << "The stack is full" << endl;
        return;
    }
    ++S.top;
    S.Stacklist[S.top] = key;
}

// 删除栈顶元素
int myStack::Pop(Stack &S)
{
    if (S.top == -1)
    {
        cout << "stack is empty!" << endl;
        return -1;
    }
    int temp = S.Stacklist[S.top];
    --S.top;
    return temp;
}

// 判断栈中的元素是否存在(存在则返回对应下标，不存在则返回0)
int myStack::find(Stack &S, int key)
{
    if (S.top == -1)
    {
        cout << "stack is empty!" << endl;
        return -1;
    }
    for (int tmp = S.top; tmp != -1; tmp--)
    {
        if (S.Stacklist[tmp] == key)
        {
            return tmp;
        }
    }
    cout << "查无此元素！" << endl;
    return 0;
}

// 删除指定元素
void myStack::delete_index(Stack &S, int key)
{
    int index = find(S, key);
    if (index <= 0)
    {
        return;
    }
    Stack tmp_S;
    while (S.top != index)
    {
        Push(tmp_S, Pop(S));
    }
    Pop(S);
    while (tmp_S.top != -1)
    {
        Push(S, Pop(tmp_S));
    }
}

// 遍历整个栈
void myStack::show(Stack &S)
{
    if (S.top == -1)
        cout << "栈为空！" << endl;
    int temp = S.top; // 定义一个临时指针
    while (temp != -1)
    {
        cout << S.Stacklist[temp] << " ";
        --temp;
    }
    cout << endl;
}

// 测试用例
void myStack::my_stack()
{
    Stack S;
    // myStack::ush(S, 1);
    myStack::Push(S, 8);
    myStack::Push(S, 5);
    myStack::Push(S, 4);
    myStack::Push(S, 2);
    myStack::show(S);
    myStack::Pop(S);
    myStack::show(S);
    myStack::delete_index(S, 2);
    myStack::delete_index(S, 5);
    myStack::show(S);
}
