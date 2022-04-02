// RECURSIVE LINEAR SEARCH - TIME EFFICIENCY

# include<iostream>
# include<stdlib.h>
# include<time.h>

using namespace std;

const long MAX = 10000;
int RecLinearSearch(int *, int, int);
void sleep(clock_t wait);

int main() 
{
    double duration;
    clock_t st, et; //start time and end time
    int a[MAX];     //array to be sorted
    int n;
    int found, Key = 100;

    srand((unsigned)time(NULL));    // send value to rand

    for(n=0; n<=MAX; n=n+500)
    {
        for(int i=0; i<n; i++)
            a[i] = rand();  //get random number

            // cout << "Enter array size:";
            // cin >> n;
            // cout << "Enter array[in ascending order]: \n";
            // for(int i=0; i<n; i++)
            //     cin >> a[i];
            // cout << "Enter the Key: ";
            // cin >> Key;

            st = clock();
            sleep ((clock_t)1 * CLOCKS_PER_SEC);
            found = RecLinearSearch(a, n, Key);
            et = clock();
            if (found == -1)
                cout << "Key not found: ";
            else
                cout << "Key found at : " << found+1 << endl;
            duration = (double)(et - st) / CLOCKS_PER_SEC;
            cout << n << "\t" << duration << " secs" << endl;
    }
    return 0;
}

int RecLinearSearch (int a[], int n, int key)
{
    if(n < 0) return -1;
    if(a[n-1] == key)
        return n;
    else
        return RecLinearSearch(a, n-1, key);
}

//pause for 1 sec
void sleep (clock_t wait)
{
    clock_t goal;
    goal = wait + clock();
    while(goal > clock())
        ;
}

