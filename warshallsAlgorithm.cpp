// TRANSITIVE CLOSURE - WARSHALL'S ALGORITHM

# include<iostream>
using namespace std;

class AdjMatrix
{
    protected:
        int **a;
        int n;
    public:
        AdjMatrix();
        void ReadAdj();
        void PrintAdj();
        void Warshall();
};

AdjMatrix :: AdjMatrix()
{
    n = 10;
    //dynamic allocation for a(10*10)
    a = new int * [n+1];
    for (int k = 0; k <= n; k++)        //allocate for rows
        a[k] = new int [n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = 0;        // no edges
}

void AdjMatrix :: ReadAdj()
{
    cout << "Enter the number of vertices: ";
    cin >> n;
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     //allocate for rows
        a[k] = new int [n+1];
    cout << "Enter the Adjacency Matrix: \n";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

void AdjMatrix :: PrintAdj()
{
    cout << "The Transitive Closure is : \n";
    for(int i =1; i <= n; i++)
    {
        for(int j = 1; j<= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void AdjMatrix :: Warshall()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
}
int main()
{
    AdjMatrix g1;
    g1.ReadAdj();
    g1.Warshall();      //find all pairs shartest path
    g1.PrintAdj();      //print the shortest paths
}

/*

1---------->2
*           |
  \         |
    \       |
      \     |
        \   |
          * *
3<----------4


Enter the number of vertices: 4
Enter the Adjacency Matrix: 
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
The Transitive Closure is :
1 1 1 1
1 1 1 1
0 0 0 0
1 1 1 1
*/