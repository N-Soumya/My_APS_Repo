#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;
 
struct Edge {
    int source, dest, weight;
};
 
void printPath(vector<int> const &parent, int vertex, int source)
{
    if (vertex < 0) {
        return;
    }
 
    printPath(parent, parent[vertex], source);
    if (vertex != source) {
        cout << ", ";
    }
    cout << vertex;
}
 
void bellmanFord(vector<Edge> const &edges, int source, int n)
{
   
    vector<int> distance (n, INT_MAX);
    distance[source] = 0;
 
    vector<int> parent (n, -1);
 
    int u, v, w, k = n;
 
   
    while (--k)
    {
        for (Edge edge: edges)
        {
           
            u = edge.source;
            v = edge.dest;
            w = edge.weight;
 
          
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                
                distance[v] = distance[u] + w;
 
               
                parent[v] = u;
            }
        }
    }
 
  
    for (Edge edge: edges)
    {
        
        u = edge.source;
        v = edge.dest;
        w = edge.weight;
 
       
        if (distance[u] != INT_MAX && distance[u] + w < distance[v])
        {
            cout << "Negative-weight cycle is found!!";
            return;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        if (i != source && distance[i] < INT_MAX)
        {
            cout << "The distance of vertex " << i << " from the source is "
                 << setw(2) << distance[i] << ". Its path is [";
            printPath(parent, i, source); cout << "]" << endl;
        }
    }
}
 
int main()
{
  
    vector<Edge> edges =
    {
      
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
 
   
    int n = 5;
 
   
    for (int source = 0; source < n; source++) {
        bellmanFord(edges, source, n);
    }
 
    return 0;
}
