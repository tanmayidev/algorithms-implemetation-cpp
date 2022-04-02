//  RECURSIVE BINARY SEARCH - TIME EFFICIENCY
# include<iostream>
# include<cstdlib>
# include<time.h>
using namespace std;

const long MAX = 10000;
int BinarySearch(int *, int, int, int, int);
void BubbleSort(int *, int);
void sleep(clock_t wait);

int main()
{
    double duration;
    clock_t st, et;     //start time and end time
    int a[MAX];         //array to be sorted
    int n;              // input array size
    int found, Key = 100;

    // send send value to rand function
    srand((unsigned)time(NULL));
    for(n=0; n<=MAX; n=n+500)
    {
        for(int i=0; i<n; i++)
            a[i] = rand();     //get a random number

            //cout << "Enter array size"
            //cin >> n;
            //cout << "Enter array [in ascending order]: \n"
            // for(int i = 0; i < n; i++)
            // cin > a[i]
            // cout << "Enter the Key: ";
            // cin >> Key;

            BubbleSort(a, n);
            st = clock();
            sleep ((clock_t)1 * CLOCKS_PER_SEC);      //1 sec delay
            found = BinarySearch(a, n, 0, n-1, Key);
            et = clock();
            if (found == -1)
                cout << "Key not found: ";
            else
                cout << "Key found at: " << found+1 << endl;
            duration = (double)(et - st) / CLOCKS_PER_SEC;
            cout << n << "\t" << duration << " secs" << endl;
    }
    return 0;
}

int BinarySearch(int a[], int n, int low, int high, int Key)
{
    int mid;
    if(low > high)  return -1;
    mid = (low + high)/2;
    if(Key == a[mid])   return mid;
    else if(Key < a[mid])
        return BinarySearch (a, n, low, mid-1, Key);
    else
        return BinarySearch (a, n, mid+1, high, Key);
}

void BubbleSort (int a[], int n)
{
    for(int i=0; i < n-1; i++)
    {
        for(int j=0; j < n-1-i; j++)
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
    }
}

//pause for 1 sec
void sleep (clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while (goal > clock())
        ; 
}
