//iNSERTION SORT

# include<iostream>
using namespace std;

const long MAX = 20;
void InsertionSort(int *, int);

int main()
{
    int a[MAX];     //array to be sorted
    int n;

    cout << "Enter the array size: ";
    cin >> n;
    cout << "Enter the array: \n";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    InsertionSort(a, n);
    cout << "The sorted array is:\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void InsertionSort(int a[], int n)
{
    int j, p, k;
    for(j = 1; j < n; j++)
    {
        k = a[j];
        for(p = j-1; (p >= 0 && k < a[p]); p--)
            a[p+1] = a[p];
        a[p+1] = k;
    }
}