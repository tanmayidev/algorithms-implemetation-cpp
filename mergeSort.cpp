//MERGESORT

# include<iostream>
using namespace std;

const int MAX = 20;
void MergeSort(int [], int, int);
void Merge(int [], int, int, int);

int main()
{
    int a[MAX];
    int n, i;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(i = 0; i < n; i++)
        cin >> a[i];
    MergeSort(a, 0, n-1);
    cout << "The sorted elements: \n";
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void MergeSort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

void Merge(int a[], int low, int mid, int high)
{
    int i, h, j, k, b[MAX];
    h = i = low;
    j = mid + 1;
    while(h <= mid && j <= high)
    {
        if(a[h] < a[j])
            b[i++] = a[h++];
        else
            b[i++] = a[j++];
    }
    if(h > mid)
        for(k = j; k <= high; k++)
            b[i++] =a[k];
        else
            for(k = h; k <= mid; k++)
                b[i++] = a[k];
        for(k = low; k <= high; k++)
            a[k] = b[k];
}