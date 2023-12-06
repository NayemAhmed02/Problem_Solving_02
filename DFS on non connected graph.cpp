#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges, bool* visited, int sv, int n)
{
    cout<<sv<<"\n";
    visited[sv] = true;

    for(int i=0; i<n; i++) {
        if(edges[sv][i] == 1 && visited[i] == false) printDFS(edges, visited, i, n);
    }
}

void DFS(int** edges, int n)
{
    bool* visited = new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    cout<<"DFS Traversal: \n";

    for(int i=0; i<n; i++) {
        if(visited[i] == false) printDFS(edges, visited, i, n);
    }

    delete [] visited;
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

    DFS(edges, n);

    // releasing memory
    for(int i=0; i<n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;


}


