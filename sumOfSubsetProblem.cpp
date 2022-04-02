/*
Find a subset of a given set S = (s1, s2,....sn) of n positive integers whose sum is equal to a given 
positive integer d. For example, if S = {1, 2, 5, 6, 8} and d = 9 there are two solutions {1, 2, 6}
and {1, 8}. A suitable message is to be displayed if the given problem instance doesn't have a solution.
*/

# include<iostream>
using namespace std;

const int MAX = 10;
int S[MAX], X[MAX];
int d;
void SumOfSub(int, int, int);

int main()
{
    int n, sum = 0;
    cout << "Enter maximum number: ";
    cin >> n;
    cout << "Enter the set in increasing order: \n";
    for(int i = 1; i <= n; i++)
        cin >> S[i];
    cout << "Enter the max. subset value(d): ";
    cin >> d;
    for(int i = 1; i <= n; i++)
        sum = sum + S[i];
    if(sum < d || S[1] > d) cout << "No Subset Possible\n";
    else    SumOfSub(0, 1, sum);     
}

void SumOfSub(int s, int k, int r)
{
    X[k] = 1;
    if((s + S[k]) == d)
    {
        for(int i = 1; i <= k; i++)
            if(X[i] == 1)   cout << S[i] << " ";
        cout << "\n";
    }
    else
        if(s + S[k] + S[k+1] <= d)
            SumOfSub(s + S[k], k + 1, r - S[k]);
    if((s + r - S[k] >= d) && (s + S[k+1] <= d))
    {
        X[k] = 0;
        SumOfSub(s, k + 1, r - S[k]);
    }
}