//DIJKSTRA'S ALGORITHM
//From a given vertex in a weighted connected graph, find the shortest paths to other vertices

#include<iostream>
using namespace std;

const int NoEdge = 100;
const int MAX = 10;

class AdjMatrix
{
    protected:
        int **a;        // adjacency matrix
        int n;          // number of vertices
        int Choose(int *);  // finds min vertex in Dist
        int Dist[MAX];
    public:
        AdjMatrix();
        void ReadAdj();
        void PrintAdj();
        void Dijkstras(int);
};

AdjMatrix :: AdjMatrix()
{
    n = 10;
    // dynamic memory allocation for a(10*10)
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     //allocate for rows
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
    for(int k = 0; k <= n; k++)     // allocate for rows
        a[k] = new int [n+1];
    cout << "Enter the Adjacency Matrix: \n";
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

void AdjMatrix :: Dijkstras(int v)
{
    int S[MAX];
    int u, i, w;
    for(i = 1; i <= n; i++)
    {
        S[i] = 0;
        Dist[i] = a[v][i];
    }
    S[v] = 1;
    Dist[v] = 1;
    i = 2;
    while(i <= n)
    {
        u = Choose(S);
        S[u] = 1;
        i++;
        for(w = 1; w <= n; w++)
        {
            if(((Dist[u] + a[u][w]) < Dist[w]) && !S[w])
                Dist[w] = Dist[u] + a[u][w];
        }
    }
    for(i = 1; i <= n; i++)
        if(i != v)
            cout << i << ": " << Dist[i] << endl;
}

int AdjMatrix :: Choose(int S[])
{
    int w, j = 1, min;
    min = NoEdge;
    for(w = 1; w <= n; w++)
    {
        if((Dist[w] < min) && (!S[w]))
        {
            min = Dist[w];
            j = w;
        }
    }
    return (j);
}

int main()
{
    AdjMatrix g1;   // undirected graph
    g1.ReadAdj();
    g1.PrintAdj();
    int s;
    cout << "Enter starting vertex: ";
    cin >> s;
    g1.Dijkstras(s);
}

/*
Enter the number of vertices: 5
Enter the Adjacency Matrix: 
0 3 100 7 100
3 0 4 2 100
100 4 0 5 6
7 2 5 0 4
100 100 6 4 0
The Adjacency Matrix is: 
0 3 100 7 100
3 0 4 2 100
100 4 0 5 6
7 2 5 0 4
100 100 6 4 0
Enter starting vertex: 1
2: 3
3: 7
4: 5
5: 9
*/