//ALL NODES REACHABLE - DFS

# include<iostream>
using namespace std;

const int MAX = 10;
//Linked ist for nodes
int Visited[MAX];
struct List
{
    int v;      //vertex number
    int w;      //weight
    struct List *link;
};

//Adjacency List class
class AdjList
{
    protected:
        List *a[MAX];   //array of pointers to Lists
        int n;          // number of vertices
    public:
        AdjList();
        void ReadAdj();
        void PrintAdj();
        int getVertices();
        void dfs(int);
};

AdjList :: AdjList()
{
    n = 10;
    for(int i = 1; i <= n; i++)
        a[i] = 0;
}

void AdjList :: ReadAdj()
{
    List *temp, *q;
    int vertex, weight;
    char choice;
    cout << "Enter number of vertices: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        do
        {
            cout << "Enter adjacent vertex and weight  for: " << i << ": ";
            cin >> vertex >> weight;
            if(vertex == 0) break;  //no adjacent vertex
            temp = new List;
            temp->v = vertex;
            temp->w = weight;
            temp->link = 0;
            if(!a[i])
                a[i] = temp;
            else
            {
                q = a[i];
                while(q->link)
                    q = q->link;
                q->link = temp;
            }
            cout << "Do you want to continue (y/n) ?";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
    return;
}

void AdjList :: dfs(int s)
{
    // s is the starting vertex
    List *q;
    int w;
    Visited[s] = 1;
    q = a[s];
    while(q)
    {
        w = q->v;
        if(!Visited[w])
        {
            cout << w << " ";
            dfs(w);
        }
        q = q->link;
    }
}

int AdjList :: getVertices()
{
    return n;
}

void AdjList :: PrintAdj()
{
    List *q;
    cout << "\nAdjacency List Output:\n";
    for(int i = 1; i <= n; i++)
    {
        q = a[i];
        for(; q; q = q->link)
            cout << "<" << i << "," << q->v << ">" << q->w << endl;
    }
}

int main()
{
    AdjList g;
    g.ReadAdj();
    g.PrintAdj();
    int s;
    cout << "Enter starting vertex :";
    cin >> s;
    cout << "Vertices reachable from: " << s << " are: ";
    g.dfs(s);
    cout << "\n"; 
}

/*

1----------->2
^ \        / *
|   \    /   |
|     \/     |
|    /  \    |
|  /      \  |
| *         *|
3----------->4

Enter number of vertices: 4
Enter adjacent vertex and weight  for: 1: 2 0
Do you want to continue (y/n) ?y
Enter adjacent vertex and weight  for: 1: 4 0
Do you want to continue (y/n) ?n 
Enter adjacent vertex and weight  for: 2: 3 0
Do you want to continue (y/n) ?n
Enter adjacent vertex and weight  for: 3: 1 0
Do you want to continue (y/n) ?y
Enter adjacent vertex and weight  for: 3: 4 0
Do you want to continue (y/n) ?n
Enter adjacent vertex and weight  for: 4: 2 0
Do you want to continue (y/n) ?n

Adjacency List Output:
<1,2>0
<1,4>0
<2,3>0
<3,1>0
<3,4>0
<4,2>0
Enter starting vertex :1
Vertices reachable from: 1 are: 2 3 4
*/