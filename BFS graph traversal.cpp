#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges, bool* visited, int sv, int n)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while(pendingVertices.size() != 0)
    {
        int curV = pendingVertices.front();
        pendingVertices.pop();

        cout<<curV<<"\n";

        for(int i=0; i<n; i++)
        {
            if(edges[curV][i] == 1 && visited[i] == false)
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

}

int main()
{
    int n,e;
    cout<<"Enter number of vertices of the graph: ";
    cin>>n;
    cout<<"Enter number of edges of the graph: ";
    cin>>e;

    int** edges = new int*[n];
    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j] = 0;
        }
    }

    cout<<"Enter edges: \n";
    for(int i=0; i<e; i++)
    {
        int st,ed;
        cin>>st>>ed;

        edges[st][ed] = 1;
        edges[ed][st] = 1;
    }

    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }

    cout<<"BFS Traversal: \n";
    printBFS(edges, visited, 1, n);

    // releasing memory
    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    delete [] visited;

}
