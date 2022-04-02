// GRAPH CONNECTEDNESS - DFS

# include<iostream>
using namespace std;

const int MAX = 10;
//Linked List for nodes

int Visited[MAX];
struct List
{
    int v; // vertex number
    int w; // weight
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
        void dfs(int, int&);
        void DFS();
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
    cout << "Enter number of Vertices: ";
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        do
        {
            cout << "Enter the adjacent vertex and weight for:" << i << ": ";
            cin >> vertex >> weight;
            if(vertex == 0)     break;  //no adjacent vertex
            temp = new List;
            temp->v = vertex;
            temp->w = weight;
            temp->link = 0;
            if(!a[i])
                a[i] = temp;
            else
            {
                q = a[i];
                while (q->link)
                    q = q->link;
                q->link = temp;
            }
            cout << "Do you want to continue (y/n)? ";
            cin >> choice;
       }while(choice == 'y' || choice == 'Y');
    }
    return;
}

void AdjList :: dfs(int s, int& c)
{
    //s is the starting vertex - here it is 1
    List *q;
    int w;
    Visited[s] = 1;
    c++;
    q = a[s];
    while(q)
    {
        w = q->v;
        if(!Visited[w])
            dfs(w, c);
        q = q->link;
    }
}

void AdjList :: DFS()
{
    int count = 0;
    dfs(1, count);
    if(count == n)  cout << "Connected\n";
    else cout << "Not Connected\n";
}

int AdjList :: getVertices()
{
    return n;
}

void AdjList :: PrintAdj()
{
    List *q;
    cout << "\nAdjacency List Output: \n";
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
    g.DFS();
    cout  << "\n";

    return 0;
}

/*
        1 --------- 2
                   /|
                /   |
              /     |
           /        |
        4-----------3

        1-----------2
        |
        |
        |
        |
        3           4
*/

