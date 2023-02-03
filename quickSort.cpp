#include <iostream>
using namespace std;
void quickSort(int a[], int low, int high)
{
    if(low<high)
    {
        int pivot = low;
        int i = low + 1;
        int j = high;
        while(i <= j)
        {
            while(a[i]<a[pivot] && i <= high)
            {
                i++;
            }
            while(a[j]>a[pivot] && j >= low)
            {
                j--;
            }
            if(i < j)
            {
                swap(a[i], a[j]);
            }
            swap(a[j], a[pivot]);
            quickSort(a, low, j - 1);
            quickSort(a, j +1, high);
        }
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
    quickSort(a, 0 , n-1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
