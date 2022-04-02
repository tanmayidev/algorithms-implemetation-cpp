//BFS - NODES REACHABLE
# include<iostream>
using namespace std;

const int MAX = 10;
int Visited[MAX];

//Linked LIst for nodes
struct List
{
    int v;  //vertex number
    int w;  //weight
    struct List *link;
};

//Adjacency List class
class AdjList
{
    protected:
        List *a[MAX];   //array of pointers to Lists
        int n;
    public:
        AdjList();
        void ReadAdj();
        void PrintAdj();
        int getVertices();
        void bfs(int);
        void Qinsert(int);      //queue insert
        int Qdelete();          // queue delete
        List *front, *rear;     // pointers to queue operations
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
        do{
            cout << "Enter adjacent vertex and weight for:" << i << ": ";
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
            cout << "You want to continue (y/n) ?";
            cin >> choice; 
        }while(choice == 'y' || choice == 'Y');
    }
    return;
}

void AdjList :: bfs(int s)
{
    List *q;
    front = rear = 0;   //initialise the queue
    Visited[s] = 1;
    while(1)
    {
        q = a[s];
        while(q)
        {
            if(!Visited[q->v])
            {
                Qinsert(q->v);
                cout << q->v << endl;
                Visited[q->v] = 1;
            }
            q = q->link;
        }
        if(!front)  return;
        s = Qdelete();
    }
}

void AdjList :: Qinsert(int x)
{
    List *q;
    q = new List;
    q-> v = x; 
    q->link = 0;
    if(!front)
    {
        front = rear = q;
        return;
    }
    rear->link = q; rear = q;
}

int AdjList :: Qdelete()
{
    int x;
    if(front)
        x = front->v;
    if(front == rear)
        front = rear =0;
    else
        front = front->link;
    
    return x;
}

int AdjList :: getVertices()
{
    return n;
}

void AdjList :: PrintAdj()
{
    List *q;
    cout << "\nAdjacency List Output : \n";
    for(int i = 1; i <= n; i++)
    {
        q = a[i];
        for(; q; q = q->link)
            cout << "<" << i << "," << q->v << "> " << q->w << endl;
    }
}

int main()
{
    AdjList g;
    g.ReadAdj();
    g.PrintAdj();
    int s;
    cout << "ENter starting vertex: ";
    cin >> s;
    cout << "Vertices reachable from: " << s << " are:\n";
    g.bfs(s);
    cout << "\n";
}

/*

1------------>2
^           / |  
|        /    |  
|      /      |
|   /         |
| /           |
|*            *
4------------>3
Enter number of vertices: 4
Enter adjacent vertex and weight for:1: 2 0
You want to continue (y/n) ?n
Enter adjacent vertex and weight for:2: 3 0
You want to continue (y/n) ?y 
Enter adjacent vertex and weight for:2: 4 0
You want to continue (y/n) ?n 
Enter adjacent vertex and weight for:3: 0 0
Enter adjacent vertex and weight for:4: 1 0
You want to continue (y/n) ?y
Enter adjacent vertex and weight for:4: 3 0
You want to continue (y/n) ?n

Adjacency List Output :
<1,2> 0
<2,3> 0
<2,4> 0
<4,1> 0
<4,3> 0
ENter starting vertex: 1
Vertices reachable from: 1 are:
2
3
4
*/