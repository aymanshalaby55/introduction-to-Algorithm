#include <iostream>
using namespace std;
// code for insertion sort
int main()
{
    int a[] = {3, 2, 4, 5, 1,0};
    for (int i = 1; i < 6; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 and a[j] < key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (auto i : a)
        cout << i << " ";
    return 0;
}