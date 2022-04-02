//KNAPSACK PROBLEM - DYNAMIC PROGRAMMING

# include<iostream>
using namespace std;

const int MAX = 30;
int MFK(int, int);
int Max(int, int);
int profits[MAX];       //profits
int weights[MAX];       //weights
int V[MAX][MAX];
int n;              // number of objects
int M;              // knapsack size

int main()
{
    int optsoln;       // optimal solution
    cout << "Enter the number of objects: ";
    cin >> n;
    cout << "Enter the weights: \n";
    for(int i = 1; i <= n; i++)
        cin >> weights[i];
    cout << "Enter the profits: \n";
    for(int i =1; i <= n; i++)
        cin >> profits[i];
    cout << "Enter the Knapsack Capacity: ";
    cin >> M;
    for(int i = 0; i <= M; i++)
        V[0][i] = 0;
    for(int i = 0; i <= n; i++)
        V[i][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= M; j++)
            V[i][j] = -1;
    optsoln = MFK(n, M);
    cout << "Optimal solution = " << optsoln << endl;
}

int MFK(int i, int j)
{
    int p;
    if(V[i][j] == -1)
    {
        if(j < weights[i])
            p = MFK(i-1, j);
        else
            p = Max(MFK(i-1, j), MFK(i-1, j-weights[i])+profits[i] );
        V[i][j] = p;
    }
    return V[i][j];
}

int Max (int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

/*
Output 1
Enter the number of objects: 3
Enter the weights: 
1 2 2
Enter the profits: 
18 16 6
Enter the Knapsack Capacity: 4
Optimal solution = 34

Output 2
Enter the number of objects: 4
Enter the weights: 
2 1 3 2
Enter the profits:
12 10 20 15
Enter the Knapsack Capacity: 5
Optimal solution = 37
*/