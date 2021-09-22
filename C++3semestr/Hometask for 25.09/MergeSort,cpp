#include <iostream>
using namespace std;

void merge(int* array, int left, int mid, int right)
{
    int lenleft = mid - left + 1;
    int lenright = right - mid;
    int *leftA = new int[lenleft];
    int *rightA = new int[lenright];
    for (size_t i = 0; i < lenleft; i++)
        leftA[i] = array[left + i];
    for (size_t j = 0; j < lenright; j++)
        rightA[j] = array[mid + 1 + j];
    int iinleft = 0;
    int iinright = 0;
    int iinmerged = left;
    while (iinleft < lenleft && iinright < lenright) {
        if (leftA[iinleft] <= rightA[iinright]) {
            array[iinmerged] = leftA[iinleft];
            iinleft++;
        }
        else {
            array[iinmerged] = rightA[iinright];
            iinright++;
        }
        iinmerged++;
    }
    while (iinleft < lenleft) {
        array[iinmerged] = leftA[iinleft];
        iinleft++;
        iinmerged++;
    }
    while (iinright < lenright) {
        array[iinmerged] = rightA[iinright];
        iinright++;
        iinmerged++;
    }
}

void mergeSort(int* array, int begin, int end)
{
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int* array, int size)
{
    for (size_t i = 0; i < size; i++)
        cout << array[i] << " ";
}


int main()
{
    int n;
    cin >> n;
    int* arr  = new int[n];
    for (size_t i = 0; i < n;i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
