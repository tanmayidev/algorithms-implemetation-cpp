//PRIM'S ALGORITHM

# include<iostream>
using namespace std;

const int MAX = 10;
const int NoEdge = 100;

class AdjMatrix
{
    protected :
        int **a;        // adjacency matrix
        int n;          // number of vertices
    public :
        AdjMatrix();
        void ReadAdj();
        void PrintAdj();
        int getVertices();
        void Prim();
};


AdjMatrix :: AdjMatrix()
{
    n = 10;
    //dynamic memory allocation for a(10*10)
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)
        a[k] = new int [n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = 0;    //no edges 
}

int AdjMatrix :: getVertices()
{
    return n;
}

void AdjMatrix :: ReadAdj()
{
    cout << "Enter the number of vertices: ";
    cin >> n;
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     // allocate for rows
        a[k] = new  int [n+1];
    cout << "Enter the Adjacency Matrix:(100 for no edge)\n ";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

void AdjMatrix :: PrintAdj()
{
    cout << "The Adjacency Matrix is: \n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void AdjMatrix :: Prim()
{
    int Visited[MAX];
    int lowcost[MAX];
    int T[MAX][2];
    int k, min, w = 0;

    for(int i = 2; i <= n; i++)
    {
        lowcost[i] = a[1][i];
        Visited[i] = 1;
    }
    for(int i = 2; i <= n; i++)
    {
        min = lowcost[2];
        k = 2;
        for(int j = 3; j <= n; j++)
            if(lowcost[j] < min)
            {
                min = lowcost[j];
                k = j;
            }
            T[i-1][1] = Visited[k];
            T[i-1][2] = k;
            //T[i-1][3] = min;
            w = w + min;    //accumulate weight
            //update all data structures
            lowcost[k] = NoEdge;
            for(int j = 2; j <= n; j++)
                if(a[k][j] < lowcost[j] && lowcost[j] != NoEdge)
                {
                    lowcost[j] = a[k][j];
                    Visited[j] = k;
                }
    }
    //print the minimum spanning tree
    for(int i = 1; i <= n-1; i++)
        cout << "<" << T[i][1] << "," << T[i][2] << ">";
    cout << endl;
    cout <<"Total Weight = " << w << endl;
}

int main()
{
    AdjMatrix g1;       // undirected graph
    g1.ReadAdj();
    g1.PrintAdj();
    g1.Prim();
}

/*
Enter the number of vertices: 5
Enter the Adjacency Matrix:(100 for no edge)
 0 11 9 7 8
11 0 15 14 13
9 15 0 12 14
7 14 12 0 6
8 13 14 6 0
The Adjacency Matrix is:
0 11 9 7 8
11 0 15 14 13
9 15 0 12 14
7 14 12 0 6
8 13 14 6 0
<1,4><4,5><1,3><1,2>
Total Weight = 33

Enter the number of vertices: 3
Enter the Adjacency Matrix:(100 for no edge)
 0 10 1
10 0 6
1 6 0
The Adjacency Matrix is:
0 10 1
10 0 6
1 6 0
<1,3><3,2>
Total Weight = 7
*/