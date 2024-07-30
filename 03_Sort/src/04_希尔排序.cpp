/**
 *  希尔排序
 *  在插入排序的基础上进行分组
 *  没有交换 比较次数也少
 *  时间复杂度
 *  最坏 O(n^2)
 *  平均 O(n^1.3)
 *  最好O(n)    -> 已经是有序的
 *  空间复杂度O(1);
 *  ！不稳定
 */

void ShellSort(int arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int val = arr[i];
            int j = i - gap;
            for (; j >= 0; j -= gap)
            {
                if (arr[j] <= val)
                {
                    break;
                }
                arr[j + gap] = arr[j];
            }
            //
            arr[j + gap] = val;
        }
    }
}