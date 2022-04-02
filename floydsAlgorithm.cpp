//FLOYD'S ALGORITHM

# include<iostream>
using namespace std;

class AdjMatrix
{
    protected:
        int **a;    //adjacency matrix
        int n;      //number of vertices
    public:
        AdjMatrix();
        void ReadAdj();
        void PrintAdj();
        void Floyd();
};

AdjMatrix :: AdjMatrix()
{
    n = 10;
    //dynamic allocation for a(10*10)
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     //allocate for rows
        a[k] = new int [n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = 0;    //no edge
}

void AdjMatrix :: ReadAdj()
{
    cout << "Enter the number of vertices: ";
    cin >> n;
    a = new int * [n+1];
    for(int k = 0; k <= n; k++) // allocate for rows
        a[k] = new int [n+1];
    cout << "Enter the Adjacency Matrix:[100 for no edge]\n";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

void AdjMatrix :: PrintAdj()
{
    cout << "The Final Adjacency Matrix is: \n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void AdjMatrix :: Floyd()
{
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if((a[i][k] + a[k][j]) < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
}

int main()
{
    AdjMatrix g1;
    g1.ReadAdj();
    g1.Floyd();         // find all pairs shortest path
    g1.PrintAdj();      // print the shortest paths
}

/*
          (2)
   1<---------------2
   | *       (7)  *
   |  \         / 
   |    \     /
   |      \ /
 3 |      /  \
   |    /      \ (6)
   *  /           \ 
   3--------------->4
        (1)

  output 1:
Enter the number of vertices: 4
Enter the Adjacency Matrix:[100 for no edge]
0 100 3 100
2 0 100 100
100 7 0 1
6 100 100 0
The Final Adjacency Matrix is:
0 10 3 4
2 0 5 6
7 7 0 1
6 16 9 0

  output 2:      
Enter the number of vertices: 5
Enter the Adjacency Matrix:[100 for no edge]
0 2 100 1 8
6 0 3 2 100
100 100 0 4 100
100 100 2 0 3
3 100 100 100 0
The Final Adjacency Matrix is:
0 2 3 1 4
6 0 3 2 5
10 12 0 4 7
6 8 2 0 3
3 5 6 4 0

*/