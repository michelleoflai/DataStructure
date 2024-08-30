/**
 *  插入排序
 *  若数据区域有序，所有排序中 效率最高的算法
 *  没有交换 比较次数也少
 *  时间复杂度
 *  最坏/平均 O(n^2)
 *  最好O(n)    -> 已经是有序的
 *  空间复杂度O(1);
 *  稳定
 */

void InsertSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int val = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] <= val)
            {
                break;
            }
            arr[j + 1] = arr[j];
        }
        //
        arr[j + 1] = val;
    }
}
