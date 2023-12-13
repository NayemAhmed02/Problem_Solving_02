#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int ele, int* parent)
{
    if(parent[ele] == ele) return ele;
    return findParent(parent[ele], parent);
}
void kruskal(Edge* edges, Edge* mst, int v, int e)
{
    // first sort the edges in non decreasing order based on their weight
    sort(edges, edges+e, compare);

    // initialize the parent for every edges
    int* parent = new int[e];
    for(int i=0; i<e; i++) {
        parent[i] = i;
    }

    // choose v-1 edges that has minimum weight
    int cnt = 0;
    int i = 0;
    while(i < e)
    {
        // find top most parent for both end of the current edge
        int sp = findParent(edges[i].source, parent);
        int dp = findParent(edges[i].destination, parent);

        // if parent are not same then it will not create any circle. we will add this edge to our MST
        if(sp != dp)
        {
            // add edge into MST
            mst[cnt] = edges[i];
            cnt++;

            // merge(union) two connected component(two disjoint set) into one
            parent[dp] = sp;
        }
        i++;
    }
}

int main()
{
    // make graph
    int V, E;
    cout<<"Enter number of vertices and edges respectively: ";
    cin>>V>>E;

    Edge* edges = new Edge[E];

    for(int i=0; i<E; i++)
    {
        int s, d, w;
        cout<<"Enter "<<i<<"th edge: ";
        cin>>s>>d>>w;

        edges[i].source = s;
        edges[i].destination = d;
        edges[i].weight = w;
    }

    // array for storing MST
    Edge* mst = new Edge[V-1];
    // call kruskal's algorithm
    kruskal(edges, mst, V, E);

    // print MST
    cout<<"\n\nour expected MST is: \n\n";
    for(int i=0; i<V-1; i++)
    {
        cout<<mst[i].source<<"    "<<mst[i].destination<<"     "<<mst[i].weight<<"\n";
    }

    // delete memory
    //delete [] edges;
   // delete [] mst;

}
