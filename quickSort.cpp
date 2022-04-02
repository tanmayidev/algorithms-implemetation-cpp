// QUICKSORT
# include<iostream>
using namespace std;

const int MAX = 20;
void QuickSort(int [], int, int, int);

int main()
{
    int a[MAX];     //array to be sorted
    int n;          // input array size
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter the array: \n";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    QuickSort(a, 0, n-1, n);
    cout << "The Sorted array is: \n";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void QuickSort(int a[], int lb, int ub, int n)
{
    int i, j, temp, pivot;
    if(lb < ub)
    {
        i = lb; j = ub + 1;
        pivot = a[lb];
        while(1)
        {
            i++;
            while(a[i] < pivot && i < ub)
                i++;
            j--;
            while(a[j] > pivot)
                j--;
            if(i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            else break;     //partition is over
        }
        a[lb] = a[j];
        a[j] = pivot;
        QuickSort(a, lb, j-1, n);
        QuickSort(a, j+1, ub, n);
    }
}