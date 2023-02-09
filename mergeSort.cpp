#include <iostream>
using namespace std;
void merge(int a[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int Left[n1], Right[n2];
    for(i = 0; i < n1; i++)
    {
        Left[i] = a[left + i];
    }
    for(j = 0; j < n2; j++)
    {
        Right[j] = a[middle + j + 1];
    }
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2)
    {
        if(Left[i] <= Right[j])
        {
            a[k] = Left[i];
            i++;
            k++;
        }
        else
        {
            a[k] = Right[j];
            j++;
            k++;
        }

    }
    while(i < n1)
    {
        a[k] = Left[i];
        k++;
        i++;
    }
    while(j < n2)
    {
        a[k] = Right[j];
        k++;
        j++;
    }
}

void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int middle = (left + (right - 1)) / 2;
        mergeSort(a, left, middle);
        mergeSort(a, middle + 1, right);
        merge(a, left, middle, right);
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
    mergeSort(a, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
