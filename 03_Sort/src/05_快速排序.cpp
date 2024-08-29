/**
 * 快速排序  递归
 * 时间 ： O(n) * O(logn) = O(n*logn)
 * 空间 ： O(n*logn)    二叉深度
 * 不稳定
 */

// 分割
int partition(int arr[], int l, int r)
{
    int val = arr[l];

    while (l < r)
    {
        while (l < r && arr[r] > val)
        {
            r--;
        }
        if (l < r)
        {
            arr[l] = arr[r];
            l++;
        }
        while (l < r && arr[l] < val)
        {
            l++;
        }
        if (l < r)
        {
            arr[r] = arr[l];
            r--;
        }
    }
    // r=l
    arr[l] = val;
    return l;
}

// 快排接口>>本体
void quickSort(int arr[], int l, int r)
{
    if (l > r)
    {
        return;
    }

    // 分割
    int pos = partition(arr, l, r);
    quickSort(arr, l, pos - 1);
    quickSort(arr, pos + 1, r);
}


// 为了和其他算法统一参数
void quickSort(int arr[], int size)
{
    return quickSort(arr, 0, size - 1);
}