#include <stdio.h> /* Include header file for printf */
#define maxV 100   /* Define a constant */
int V, E, x, y;    /* Declare variables */
int a[maxV][maxV]; /* Declare a two dimensional array */
int visited[maxV];
int sequence[maxV];
int parent[maxV];
int start;
int count = 0, componentcount = 0; /* Declare and initialize variable */

void read_graph(void); /* Function prototype */
void print_graph(void);
void dfs(int);

int main() /* Main program. */
{
    read_graph();  /* call function to input graph adjacency matrix */
    print_graph(); /* call function to output graph adjacency matrix */
}

void read_graph(void) /* Function to read graph adjacency matrix */
{
    int edge, x;
    printf("\nInput number of vertices :");
    scanf("%d", &V);
    if (V > maxV)
        printf("Exceed the maximum number of vertices permitted");
    else
    {
        printf("\nEnter starting vertex");
        scanf("%d",&start);
        for (x = 1; x <= V; x++)
            //set all nodes as not visited and no parent nodes
            visited[x] = 0;
            parent[x] = 0;
            for (y = 1; y <= V; y++)
                a[x][y] = 0;
        for (x = 1; x <= V; x++)
            for (y = x; y <= V; y++)
            {
                printf("\na[ %d ][ %d ]=", x, y);
                scanf("%d", &edge);
                a[x][y] = edge;
                a[y][x] = edge;
            }

        componentcount++;   
        printf("\nVisiting sequence of component no.%d : ",componentcount);
        dfs(start);  
        //loops through rest of vetices
        for (int i = V; i >=1; i--)
        {
            //if not any is unvisited, start DFS for that node. in 1st count of dfs,
            //it will conduct search for  all nodes (if connected), after returning here and going to next
            //iteration, if unvisited means new parent component is found and start search from there.
            if (visited[i] == 0)
            {                
                componentcount++;   
                printf("\nVisiting sequence of component no.%d : ",componentcount);
                dfs(i);           
            }
        }
        printf("\nTotal Components of graph: %d", componentcount);
        printf("\nVisiting sequence of graph: ");
        for (int i = 0; i <V; i++)
        {
            printf("%d ",sequence[i]);
        }
        printf("\nParents of graph: ");
        for (int i = 1; i<=V; i++)
        {
            if (parent[i] == 0)
            {
                printf("\nNode %d does not have a parent", i);
            }
            else
                printf("\nParent of node %d is node %d",i, parent[i]);
            
        }    
        printf("\n");
    }
}
void print_graph(void) /* Function to print graph adjacency matrix */
{
    int x, y;
    for (x = 1; x <= V; x++)
        for (y = 1; y <= V; y++)
        {

            printf("%d ", a[x][y]);
            if (y == V)
            {
                printf("\n");
            }
        }
}

void dfs(int x)
{
    //add node to sequence, set as visited and increase visited node counter
    sequence[count] = x;
    visited[x] = 1;
    count++;
    for (int b = V; b >=1; b--)
    {
        
        //check if edge is valid and not visited
        if (!visited[b]&&a[x][b] ==1)
        {
            //set current node as parent of next node
            parent[b] = x;
            //continue the search with each valid unvisited node
            dfs(b);
            printf("\n(%d,%d) tree edge", x,b);
            
        }
        
        
    }
    
    for (int b = 1; b <=V; b++)
        {
            if (a[x][b] == 1 && parent[b] != x && parent[x] != b)
            {
                printf("\n(%d,%d) back edge ", x,b);
                printf("\nIt has a backedge, hence, it contains a cycle");
            }
            
        }
    
}
