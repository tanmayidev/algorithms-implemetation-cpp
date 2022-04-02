// n - QUEENS PROBLEM - BACKTRACKING

# include<iostream>
# include<math.h>
using namespace std;

int const MAX = 20;
void Display(int [], int);
void nQueens(int);
int Place(int [], int);

int main()
{
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n;
    cout << "The Solution to Queens Problem is: " << n << endl;
    nQueens(n);
}

void nQueens(int n)
{
    int x[MAX];
    int k;
    x[0] = -1;
    k = 0;     // initialize the row
    while(k >= 0)
    {
        x[k] = x[k] + 1;    //goto the next column
        while(x[k] < n && !Place(x, k))
            x[k] = x[k] + 1;
        if(x[k] < n)    //place the queen
            if(k == n-1)
                Display(x, n);
            else
            {
                k++;    //try for the next queen
                x[k] = -1;
            }
        else
            k--;    //backtrack (queen can't be placed)
    }
}

//returns 1, if the queen can be placed in kth row
//returns 0, otherwise
int Place(int x[], int k)
{
    int i;
    for(i = 0; i < k; i++)
        if(x[i] == x[k] || (abs(x[i] - x[k]) == abs(i-k)))
            return 0;
    return 1;
}

void Display(int x[], int n)
{
    char Chessboard[MAX][MAX];
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            Chessboard[i][j] = 'x';
    for(i = 0; i < n; i++)
        Chessboard[i][x[i]] = 'Q';
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cout << Chessboard[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}