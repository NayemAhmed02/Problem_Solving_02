#include<bits/stdc++.h>
using namespace std;

#define V 6

void printDistance(int distance[V][V])
{
    cout<<"Resulted shortest path for every pair of vertices are given below: \n\n";
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cout<<distance[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void Floyd_Warshall(int graph[V][V])
{
    // first make V*V distance matrix and initialize it's value
    int distance[V][V];
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            // set diagonal position to zero.
            if(i == j) distance[i][j] = 0;
            // if there is no edge from i to j then initialize to infinity
            else if(graph[i][j] == 0) distance[i][j] = INT_MAX;
            // if there is a edge from i to j then take it as it is
            else distance[i][j] = graph[i][j];
        }
    }

    // take Kth vertex as the intermediate vertex
    for(int k=0; k<V; k++)
    {
        // check there is a better path or not, if better path exist then update the value
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
                {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    // print result
    printDistance(distance);
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

    // call Floyd-Warshall algorithm
    Floyd_Warshall(graph);

    return 0;
}
