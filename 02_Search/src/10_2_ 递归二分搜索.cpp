/**
 * 递归实现 二分搜索
 */

int BinarySearch2(int arr[], int i, int j, int val)
{
    if (i > j)
    {
        return -1;
    }
    int mid = (i + j) / 2;
    if (arr[mid] == val)
    {
        return mid;
    }
    else if (arr[mid] > val)
    {
        return BinarySearch2(arr, i, mid - 1, val);
    }
    else
    {
        return BinarySearch2(arr, mid + 1, j, val);
    }
}