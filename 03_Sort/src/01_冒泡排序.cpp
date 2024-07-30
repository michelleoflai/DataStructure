/**
 * 基础排序：
 * 冒泡排序 时间复杂度 O(n^2)    空间复杂度O(1) 稳定    效率最低，交换次数太对  
 *        
 */

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // 优化：一趟中没有任何交换说明排序结束
        bool isChange = false;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                isChange = true;
            }
        }
        if (!isChange)
        {
            // 说明一趟中没有任何交换 排序结束
            return;
        }
    }
}