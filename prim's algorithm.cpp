#include<bits/stdc++.h>
using namespace std;
#define V 6



int findMinCostVertex(int weight[], bool visited[])
{
    int minWeight = INT_MAX, minVertex;

    for(int i=0; i<V; i++)
    {
        if(weight[i] < minWeight && visited[i] == false)
        {
            minWeight = weight[i];
            minVertex = i;
        }
    }

    return minVertex;
}

void printMST(int parent[], int weight[])
{
    for(int i=1; i<V; i++)
    {
        cout<<parent[i]<<"\t"<<i<<"\t"<<weight[i]<<"\n";
    }
}

void primMST(int graph[V][V])
{
    int parent[V], weight[V];
    bool visited[V];

    for(int i=0; i<V; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    // choose 0th vertex as starting vertex of MST
    weight[0] = 0;
    parent[0] = -1;

    for(int cnt = 0; cnt < (V-1); cnt++)
    {
        // find the minimum cost vertex that are not included in MST
        int minVertex = findMinCostVertex(weight, visited);

        // include minimum cost vertex into MST
        visited[minVertex] = true;

        // Update weight and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for(int i=0; i<V; i++)
        {
            if(graph[minVertex][i] > 0 && visited[i] == false)
            {
                if(graph[minVertex][i] < weight[i])
                {
                    weight[i] = graph[minVertex][i];
                    parent[i] = minVertex;
                }
            }
        }
    }

    printMST(parent, weight);
}
int main()
{
    int graph[V][V] = { { 0, 2, 3, 5, 0, 0 },
        { 2, 0, 4, 8, 0, 0 },
        { 3, 4, 0, 10, 7, 11 },
        { 5, 8, 10, 0, 7, 6 },
        { 0, 0, 7, 7, 0, 4 },
        { 0, 0, 11, 6, 4, 0 }
    };

    // Print the solution
    primMST(graph);

    return 0;
}
