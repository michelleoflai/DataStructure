/**
 * 基数排序
 */
#include <vector>
#include <string>

using namespace std;

void RadixSort(int arr[], int size)
{
    int maxData = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            maxData = arr[i];
        }
    }
    int len = to_string(maxData).size();

    vector<vector<int>> vecs;
    int mod = 10;
    int dev = 1;

    for (int j = 0; j < len; j++, mod *= 10, dev *= 10)
    {
        vecs.resize(10);
        for (int i = 0; i < size; i++)
        {
            int idx = arr[i] % mod / dev;
            vecs[idx].push_back(arr[i]);
        }
        int idx = 0;
        for (auto vec : vecs)
        {
            for (auto v : vec)
            {
                arr[idx++] = v;
            }
        }
        vecs.clear();
    }
}