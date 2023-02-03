#include <iostream>
#include <algorithm>
using namespace std;
void heapify(int a[], int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && a[left] > a[max])
    {
        max = left;
    }
    if(right < n && a[right] > a[max])
    {
        max = right;
    }
    if(max != i)
    {
        swap(a[i], a[max]);
        heapify(a, n, max);
    }
}
void heapSort(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main()
{
    int n, a[100];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    heapSort(a, n);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
