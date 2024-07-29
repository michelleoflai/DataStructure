/**
 * 非递归实现 二分搜索
 */
#include <iostream>
using namespace std;

int BinarySerch(int arr[], int size, int val)
{
    int first = 0;
    int last = size - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] > val)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}