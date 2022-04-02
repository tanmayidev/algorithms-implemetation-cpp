// KRUSKAL'S ALGORITHM
# include<iostream>
using namespace std;

int const MAX = 20;
int Parent [MAX];
struct Edges {
    int weight;
    int u;
    int v;
};

class AdjMatrix
{
    protected:
        int **a;       //adjacency matrix
        int n;          // number of vertices
        struct Edges E[MAX * (MAX-1)/2];
        int Ecount;
        void EdgeList();
        int Find(int);
        void Union(int, int);
    public:
        AdjMatrix();
        void ReadAdj();
        void PrintAdj();
        void Kruskals();
        void SortEdges();
};

AdjMatrix :: AdjMatrix()
{
    Ecount = 0;
    n = 10;
    //dynamic memory allocation for a(10*10)
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     // allocate for rows
        a[k] = new int [n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = 0;    // no edges
}

void AdjMatrix :: ReadAdj()
{
    cout << "Enter the number of vertices: ";
    cin >> n;
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     //allocate for rows
        a[k] = new int [n+1];
    cout << "Enter the Adjacency matrix: \n";
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

void AdjMatrix :: EdgeList()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] != 1000)
            {
                E[Ecount].weight = a[i][j];
                E[Ecount].u = i;
                E[Ecount].v = j;
                Ecount++;
            }
}

void AdjMatrix :: Kruskals()
{
    int i = 0, j, k, s;
    int mincost = 0;
    struct Edges temp;
    int a, b, w;
    int T[MAX] [2];     //minimumm weight spanning tree
    int ET = 0;         //number of edges added to T
    EdgeList();         //construct the edges list from
    SortEdges();        //sort the edge list
    for(s = 1; s <= n; s++)
        Parent[s] = 0;
    int index = 1;
    while(i < n-1 && Ecount)
    {
        temp = E[index];    //get the edge
        a = temp.u;
        b = temp.v;
        w = temp.weight;
        j = Find(a) ;
        k = Find(b) ;

        if(j != k)      // does it form a cycle ?
        {
            i++;
            T[i][1] = a;
            T[i][2] = b;
            ET++;   //accumulate number of edges added
            mincost += w;
            Union(j, k);
        }
        index++;    //pick the next edge from edge array
    } 
    if(i != n-1)    cout << "No Spanning Tree possible\n";
    else    cout << "Min cost = " << mincost << endl;

    for(i = 1; i <= ET; i++)
        cout << "Edge = " << T[i][1] << "," << T[i][2] << endl;
}

int AdjMatrix :: Find(int i)
{
    while (Parent[i])
        i = Parent[i];
    return i;
}

void AdjMatrix :: Union(int i, int j)
{
    Parent[j] = i;
}

//sort the weight of edges
// for efficient implementation, use a minheap
void AdjMatrix :: SortEdges()
{
    for(int i = 1; i < Ecount; i++)
        for(int j = 1; j < Ecount-i; j++)
            if(E[j].weight > E[j+1].weight)
            {
                struct Edges temp;
                temp = E[j];
                E[j] = E[j+1];
                E[j+1] = temp;
            }
}

int main()
{
    AdjMatrix g1; // undirected graph
    g1.ReadAdj();
    g1.PrintAdj();
    g1.Kruskals();

    return 0;
}

/*
output 1
Enter the number of vertices: 3
Enter the Adjacency matrix: 
0 10 1
10 0 6
1 6 0
The Adjacency Matrix is: 
10 0 6
1 6 0
Min cost = 7
Edge = 1,3
Edge = 2,3

output 2
Enter the number of vertices: 7
Enter the Adjacency matrix: 
0 28 100 100 100 10 100
28 0 16 100 100 100 14
100 16 100 12 100 100 100
100 100 12 0 22 100 18
100 100 100 22 0 25 24
10 100 100 100 25 0 100 
100 14 100 18 24 100 0
The Adjacency Matrix is: 
0 28 100 100 100 10 100
28 0 16 100 100 100 14
100 16 100 12 100 100 100
100 100 12 0 22 100 18 
100 100 100 22 0 25 24
10 100 100 100 25 0 100
100 14 100 18 24 100 0
Min cost = 99
Edge = 1,6
Edge = 3,4
Edge = 2,7
Edge = 2,3
Edge = 4,5
Edge = 5,6
*/