/**
 * 手撕数组
 */

#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
#define NO1 0 // 手撕数组
#define NO2 0 // 字符串逆序   双指针知识点
#define NO3 1 // 整型数组，偶数调整到数组左边，奇数调整到数组右边   头条的面试

using namespace std;

#if NO3
void change(int arr[], int size)
{
    int *p = arr;
    int *q = arr + size - 1;
    while (p < q)
    {
        while (p < q)
        {
            if ((*p & 0x1) == 1)
            {
                break;
            }
            p++;
        }
        while (p < q)
        {
            if ((*q & 0x1) == 0)
            {
                break;
            }
            q--;
        }

        int tmp = *p;
        *p = *q;
        *q = tmp;
        p++;
        q--;
    }
}

#endif

#if NO2

void reverse(char str[])
{
    char *p = str;
    char *q = str + strlen(str) - 1;
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}

#endif

#if NO1
class Array
{
public:
    Array(int size = 10) : mCur(0), mCap(size)
    {
        mpArr = new int[mCap]();
    };
    ~Array()
    {
        delete[] mpArr;
        mpArr = nullptr;

        /* ‘delete’ 执行后 mpArr指向的 堆上的空间已经被释放，但是 mpArr仍然指向该空间 此时mpArr为野指针 */
    };

public:
    void push_back(int val)
    {
        if (mCur == mCap)
        {
            expand(2 * mCap); // O(n)
        }
        mpArr[mCur++] = val; // O(1)
    }

    // O(1)
    void pop_back()
    {
        if (mCur == 0)
        {
            return;
        }
        mCur--;
    }
    void insert(int pos, int val)
    {
        if (pos < 0 || pos > mCur)
        {
            return; // throw "pos invalid"
        }
        if (mCur == mCap)
        {
            expand(2 * mCap);
        }

        // 移动元素 O(n)
        for (int i = mCur; i != pos; i--)
        {
            mpArr[i] = mpArr[i - 1];
        }

        mpArr[pos] = val;
        mCur++;
    }
    void erase(const int pos)
    {
        if (pos < 0 || pos >= mCur)
        {
            return;
        }

        // 移动元素 O(n)
        for (int i = pos; i != mCur - 1; i++)
        {
            mpArr[i] = mpArr[i + 1];
        }
        mCur--;
    }

    int find(int val)
    {
        for (int i = 0; i < mCur; i++) // O(n), 如果是有序数组用二分查找是O(logn)
        {
            if (mpArr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void show() const
    {
        for (int i = 0; i < mCur; i++)
        {
            cout << mpArr[i] << " ";
        }
        cout << endl;
    }

private:
    // 内部数组扩容接口
    void expand(int size)
    {
        int *p = new int[size];
        memcpy(p, mpArr, sizeof(int) * mCap);
        delete[] mpArr;

        mpArr = p;
        mCap = size;
    }

private:
    int *mpArr; // 指向可扩容的数组内存,因为数组开在堆空间，没有名字，给一个指针指向对空间的数组
    int mCap;   // 容量
    int mCur;   // 当前位置
};
#endif

void main01()
{
#if NO1
    Array arr;

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 100 + 1);
    }
    arr.show();
    arr.pop_back();
    arr.show();
    arr.erase(3);
    arr.show();
    arr.insert(4, 101);
    arr.show();
    int pos = arr.find(101);
    if (pos > 0)
    {
        cout << "found" << endl;
        arr.erase(pos);
    }
    arr.show();
#endif

#if NO2

    char str[] = "abcdefghijklmnopq";
    reverse(str);
    for (int i = 0; i < strlen(str); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

#endif

#if NO3
    int arr[15] = {0};
    srand(time(0));
    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
    change(arr, 15);
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;
#endif
}