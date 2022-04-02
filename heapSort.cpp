// HEAPSORT

# include<iostream>
using namespace std;

const long MAX = 100;
void HeapConstruction(int *, int);
void HeapSort(int *, int);
int MaxDelete(int [], int&);

int main()
{
    int a[MAX]; //array to be sorted
    int n;      //input array size
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter the array: \n";
    for(int i=1; i <= n; i++)
        cin >> a[i];
    HeapSort(a, n);
    cout << "The Sorted array is: \n";
    for(int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void HeapSort(int a[], int n)
{
    int i;
    HeapConstruction(a, n);
    for(i=n; i>=1; i--)
        a[i] = MaxDelete(a, n);
}

void HeapConstruction(int heap[], int n)
{
    int i, e, j;
    //start from middle of a and move up to 1
    for(i = n/2; i >= 1; i--)
    {
        e = heap[i];    //save root of subtree
        j = 2*i;        //left child and c+1 is right child
        while(j <= n)
        {
            if(j < n && heap[j] < heap[j+1])
                j++;    //pick larger of children
            if(e >= heap[j])    break;     //is a max heap
            heap[j/2] = heap[j];        // move the child to root
            j *= 2;     // go to the next level
        }
        heap[j/2] = e;
    }
}

int MaxDelete (int heap[], int& n)
{
    int x, j, e, i;
    if(n == 0)  return -1;
    x = heap[1];       //save the maximum element
    e = heap[n];       //get the last element
    (n)--;

    //Heap the structure again
    i = 1; j = 2;
    while(j <= n)
    {
        if(j < n && heap[j] < heap[j+1])
            j++;    //pick larger of two children
        if(e >= heap[j])    break;  //subtree is heap
        heap[i] = heap[j];  //move the child to root
        i = j;
        j *= 2;     //go to the next level
    }
    heap[i] = e;
    return x;
}