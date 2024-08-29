/**
 * 选择排序 时间复杂度O(n^2)  空间复杂度O(1) 不稳定
 */

void ChoiceSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) // O(n)
    {
        int minIndx = i;
        for (int j = i + 1; j < size; j++) // O(n)
        {
            if (arr[j] < arr[minIndx])
            {
                minIndx = j;
            }
        }

        if (arr[i] != arr[minIndx])
        {
            int tmp = arr[i];
            arr[i] = arr[minIndx];
            arr[minIndx] = tmp;
        }
    }
}