#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int carry = 0;
    vector<int> c(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int value = a[i] + b[i] + carry;
        if (value > 1)
        {
            if (value == 2)
            {
                c[i + 1] = 0;
                carry = 1;
            }
            else
            {
                c[i + 1] = 1;
                carry = 1;
            }
        }//hello branch
        else
            c[i + 1] = value;
    }
    c[0] = carry;
    for (auto i : c)
        cout << i << " ";
}