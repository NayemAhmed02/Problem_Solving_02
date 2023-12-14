#include<bits/stdc++.h>
using namespace std;

#define E 8
#define V 5

void printBellmanFord(int distance[], int sv)
{
    cout<<"Source vertex is: "<<sv<<"\n\n";
    for(int i=0; i<V; i++)
    {
        if(i == sv)
            continue;
        cout<<"Minimum distance from vertex "<<sv<<" to vertex "<<i<<" is: "<<distance[i]<<"\n";
    }
}

void bellman_ford(int graph[E][3], int sourceVertex)
{
    // initialize all vertex distance to infinity
    int distance[V];
    for(int i=0; i<V; i++)
    {
        distance[i] = INT_MAX;
    }

    // set source vertex distance to zero
    distance[sourceVertex] = 0;

    // perform relaxation for every edges v-1 times
    for(int j=1; j<V; j++)
    {
        bool anyModification = false;

        for(int i=0; i<E; i++)
        {
            int sv = graph[i][0]; // source vertex
            int dv = graph[i][1]; // destination vertex
            int wt = graph[i][2]; // weight

            if(distance[sv] != INT_MAX && distance[sv] + wt < distance[dv])
            {
                distance[dv] = distance[sv] + wt;
                anyModification = true;
            }
        }

        if(anyModification == false) break;
    }

    // check for negative cycle
    for(int i=0; i<E; i++)
    {
        int sv = graph[i][0]; // source vertex
        int dv = graph[i][1]; // destination vertex
        int wt = graph[i][2]; // weight

        if(distance[sv] != INT_MAX && distance[sv] + wt < distance[dv])
        {
            cout<<"There is negative cycle in the graph. So shortest path can not be calculate.\n";
            return;
        }
    }

    // print shortest path
    printBellmanFord(distance, sourceVertex);
}

int main()
{
    int graph[8][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };

    // Bellman-Ford algorithm
    int sv;
    cout<<"Enter Source vertex: ";
    cin>>sv;

    bellman_ford(graph, sv);

    return 0;

}

