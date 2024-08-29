/**
 * 堆排序
 */
#include <iostream>

void SiftDown(int arr[], int i, int size)
{
    int val = arr[i];
    while (i < size / 2)
    {
        int child = 2 * i + 1;
        if ((child + 1) < size && arr[child + 1] > arr[child])
        {
            child += 1;
        }
        // 如果子节点不大于父节点，退出循环
        if (val >= arr[child])
        {
            break;
        }
        // 将较大的子节点值上移
        arr[i] = arr[child];
        i = child; // 更新位置，继续向下筛选
    }
    arr[i] = val;
}

void HeapSort(int arr[], int size)
{
    // 1 调整为大根堆

    // 非叶子节点 循环遍历
    int n = size - 1; // 最后一个元素位置
    // 从(n-1)/2 遍历到 0
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        SiftDown(arr, i, size);
    }

    // 此时堆顶元素最大

    // 2 堆顶和末尾元素交换
    for (int i = n; i > 0; i--)
    {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        SiftDown(arr, 0, i);
    }
}