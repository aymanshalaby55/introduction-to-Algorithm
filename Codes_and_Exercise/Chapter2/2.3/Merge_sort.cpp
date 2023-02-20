#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    // space complexity is O(n) where we have to initalize left and right array 
    // n1 + n2 = n 
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int p = 0; p < k; p++)
    {
        arr[left + p] = temp[p];
    }
}
/*
-the algorithm will still divide the array
into halves recursively until it reaches subarrays of length 1 or 0,

-Then, the algorithm will start merging the sorted subarrays together, but because they are already sorted, the comparisons required to merge them will be minimized,
resulting in a faster sorting time.

-it's worth noting that Merge Sort has a worst-case time complexity of O(n log n) regardless 
of whether the input array is already sorted or not

*/
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    { // base case  : where if l >= r then the subarray has at most one elment and it's already sorted
        return;
    }
    
    /*
    divide step take : O(1)
    conquer step take :O(n/2) for each step
    combine step take : O(n) which is the Merge function
    - then the :  
    T(n) = O(1) || C--> constant            if n == 1
    T(n) = 2 T(n/2) + O(n) || O(n log(n))  if n > 1
    */
    
    int mid = left + (right - left) / 2; //divide step
    
    mergeSort(arr, left, mid); //conquer step
    mergeSort(arr, mid + 1, right);//conquer step
    
    merge(arr, left, mid, right);//combine step
}

int main()
{
    vector<int> arr = {4, 2, 7, 1, 9, 5, 8, 3, 6};

    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
