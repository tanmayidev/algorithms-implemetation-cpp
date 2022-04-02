//BINOMIAL COEFFICIENT - DYNAMIC PROGRAMMING

# include<iostream>
using namespace std;

int BC(int, int);

int main()
{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    if(n < k)
        cout << "Invalid ( n should be greater than k)\n";
    else
        cout << "BC = " << BC(n, k) << endl;
}

int BC(int n, int k)
{
    int c[10][10];
    for(int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i-1; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    return c[n][k];
}