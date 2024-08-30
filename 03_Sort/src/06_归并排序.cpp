/**
 * 归并排序
 *
 *      递->归并
 */

void Merge(int arr[], int l, int m, int r, int *p)
{
    // int *p = new int[r - l + 1];
    int i = l, j = m + 1;
    int idx = 0;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            p[idx++] = arr[i++];
        }
        else
        {
            p[idx++] = arr[j++];
        }
    }
    while (i <= m)
    {
        p[idx++] = arr[i++];
    }
    while (j <= r)
    {
        p[idx++] = arr[j++];
    }
    for (i = 0, j = l; j <= r; i++, j++)
    {
        arr[j] = p[i];
    }

    // delete[] p;
}

void MergeSort(int arr[], int begin, int end, int *p)
{
    if (begin >= end)
    {
        return;
    }

    int mid = (begin + end) / 2;

    // 递到只剩一个元素
    MergeSort(arr, begin, mid, p);
    MergeSort(arr, mid + 1, end, p);

    // 归并
    Merge(arr, begin, mid, end, p);
}

// 统一测试接口
void MergeSort(int arr[], int size)
{
    int *p = new int[size];
    return MergeSort(arr, 0, size - 1, p);
    delete[] p;
}
