#include<bits/stdc++.h>
using namespace std;

#define V 6

int findMinDistanceVertex(int distance[], bool visited[])
{
    int minDistance = INT_MAX, minDistanceVertex;

    for(int i=0; i<V; i++)
    {
        if(visited[i] == false && distance[i] < minDistance)
        {
            minDistance = distance[i];
            minDistanceVertex = i;
        }
    }

    return minDistanceVertex;
}

void printDijkstra(int distance[], int sv)
{
    cout<<"Source vertex is: "<<sv<<"\n\n";
    for(int i=0; i<V; i++)
    {
        if(i == sv)
            continue;
        cout<<"Minimum distance from "<<sv<<" vertex to "<<i<<" is: "<<distance[i]<<"\n";
    }
}

void dijkstra(int graph[V][V], int sourceVertex)
{
    // initialize distance of all vertices by infinity and all are unvisited.
    int distance[V];
    bool visited[V];
    for(int i=0; i<V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    // initialize sourceVertex distance by 0
    distance[sourceVertex] = 0;

    for(int i=1; i<V; i++)
    {
        // find the minimum distance vertex among all unvisited vertex
        int minDisVertex = findMinDistanceVertex(distance, visited);

        // mark this minimum distance as visited
        visited[minDisVertex] = true;

        // perform relaxation operation for all adjacent vertex of current Vertex (minDisVertex) those are not visited.
        for(int i=0; i<V; i++)
        {
            if(graph[minDisVertex][i] > 0 && visited[i] == false)
            {
                if(distance[minDisVertex] != INT_MAX && ((distance[minDisVertex] + graph[minDisVertex][i]) < distance[i]))
                {
                    distance[i] = distance[minDisVertex] + graph[minDisVertex][i];
                }
            }
        }
    }
    // print the constructed distance array
    printDijkstra(distance, sourceVertex);

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

    // Dijkstra's algorithm
    int sv;
    cout<<"Enter source vertex: ";
    cin>>sv;
    dijkstra(graph, sv);

    return 0;
}
