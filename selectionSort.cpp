//SELECTION SORT - TIME EFFICIENCY
# include<iostream>
# include<stdlib.h>
# include<time.h>
using namespace std;

const long MAX = 10000;
void SelectionSort(int *, int);

int main() 
{
    double duration;
    clock_t st, et;     //start time and end time
    int a[MAX];         //array to be sorted
    int n;              // input array size
    // cout << "Enter n: ";
    // cin >> n;

    //send value to rand function
    srand((unsigned)time(NULL));
    for(n = 0; n <= MAX; n = n+500)
    {
        for(int i = 0; i < n; i++)
            a[i] = rand();      //get a random number
            // cout << "Enter the array: \n";
            // for(int i = 0; i < n; i++){
            //     cin >> a[i];
            // }
            st = clock();
            SelectionSort(a, n);
            et = clock();
            /*
            cout << "The sorted array is: \n";
            for(int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            */
           duration = (double)(et - st) / CLOCKS_PER_SEC;
           cout << n << "\t" << duration << " secs" << endl;
    }
    return 0;
}

void SelectionSort ( int a[], int n)
{
    int min, temp;
    for(int i = 0; i < n-1 ; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
            if(a[j] < a[min])   min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}