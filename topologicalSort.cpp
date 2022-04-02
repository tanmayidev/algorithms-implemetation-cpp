//TOPOLOGICAL SORT
// Obtain the topological ordering of vertices in a given digraph

# include<iostream>
# include<stdlib.h>
using namespace std;

const int MAX = 100;
const int NoEdge = 100;

class Stack {
    private:
    int items[MAX];
    int top;
    public:
    Stack() {
        top = -1;
    }
    void Push(int x) {
        items[++top] = x;
    }
    int Pop() {
        return (items[top--]);
    }
    int getTop() {
        return top;
    }
};

class AdjMatrix
{
    protected:
        int **a;        //adjacency matrix
        int n;          //number of vertices
        int pos[MAX];
        int T[MAX];     //contains topological order
        int Begin (int);
        int NextVertex(int);
    public:
        AdjMatrix();
        void ReadAdj();
        void PrintAdj();
        void PrintTopo();
        int Topological();
};

AdjMatrix :: AdjMatrix()
{
    n = 10;
    //dynamic memory allocation for a(10*10)
    a = new int * [n+1];
    for(int k = 0; k <= n; k++)     //allocate for rows
        a[k] = new int [n+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            a[i][j] = 0;    //no edges
}

void AdjMatrix :: ReadAdj()
{
    cout << "Enter the number of vertices: ";
    cin >> n;
    a = new int * [n+1];
    for(int k = 0; k <= n; k++) //allocate for rows
        a[k] = new int [n+1];
    cout << "Enter the Adjacency matrix: \n";
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
}

void AdjMatrix :: PrintAdj()
{
    cout << "The AdjacencyMatrrix is: \n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int AdjMatrix :: Topological()
{
    int Indegree[MAX];
    int u;
    Stack S;
    //Fill Indegrees for each vertex
    for(int i = 1; i <= n; i++)
        Indegree[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        u = Begin(i);
        while(u)
        {
            Indegree[u]++;
            u = NextVertex(i);
        }
    }

    //Push the vertices with zero indegrees
    for(int i = 1; i <= n; i++)
        if(!Indegree[i])    S.Push(i);
    //Generate the topological ordering
    int i = 1;
    while (S.getTop() != -1)
    {
        int w;
        w = S.Pop();
        T[i++] = w;
        u = Begin(w);
        while(u)
        {
            Indegree[u]--;
            if(!Indegree[u])    S.Push(u);
            u = NextVertex(w);
        }
    }
    if( i == n+1)
        return 1;
    else return 0;
}

void AdjMatrix :: PrintTopo()
{
    cout << "The Topological ordering is: " << endl;
    if(Topological())
    {
        for(int i = 1; i <= n; i++)
            cout << T[i] << " ";
        cout << endl;
    }
    else cout << "No Topological ordering possible\n";
}

int AdjMatrix :: Begin(int i)
{
    for(int j = 1; j <= n; j++)
        if(a[i][j] != NoEdge)
        {
            pos[i] = j;
            return j;
        }
        pos[i] = n + 1;
        return 0;
}

int AdjMatrix :: NextVertex(int i)
{
    for(int j = pos[i]+1; j <= n; j++)
    if(a[i][j] != NoEdge)
    {
        pos[i] = j;
        return j;
    }
    pos[i] = n+1;
    return 0;
}
int main()
{
    AdjMatrix g1;
    cout << "Enter 100 for diagonal elements and np edges:\n";
    g1.ReadAdj();
    g1.PrintAdj();
    g1.PrintTopo();
}

/*
output 1:   1
            * \
            |   \
            |     \
            |       *
            2--------* 3
Enter 100 for diagonal elements and np edges:
Enter the number of vertices: 3
Enter the Adjacency matrix: 
100 100 1
1 100 1
100 100 100
The AdjacencyMatrrix is: 
100 100 1 
1 100 1 
100 100 100 
The Topological ordering is: 
2 1 3

output 2:           1
                   * |
                   | |
                   | |
                   | *
                    2
Enter 100 for diagonal elements and np edges:
Enter the number of vertices: 2
Enter the Adjacency matrix: 
100 1
1 100
The AdjacencyMatrrix is: 
100 1 
1 100 
The Topological ordering is: 
No Topological ordering possible

*/