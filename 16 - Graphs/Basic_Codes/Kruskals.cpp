#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
    void setParameters(int source, int destination, int weight)
    {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

bool operator<(const Edge &e1, const Edge &e2)
{
    return e1.weight < e2.weight;
}

// Returns true if vertices v1 and v2 have the same original ancestor
int returnOldestAncestor(int *parent, int vertex)
{
    int i = vertex;
    while (i != parent[i])
    {
        i = parent[i];
    }
    return i;
}

Edge *Kruskals(Edge *input, int v, int e)
{
    // sorting in increasing order
    sort(input, input + e);

    // MST will have size v-1
    Edge *MST = new Edge[v - 1];

    // For finding original ancestor, initializing as respective postions
    // ie, for a vertex i, its parent will be parent[i]
    int *parent = new int[v];
    for (int i = 0; i < v; ++i)
    {
        parent[i] = i;
    }

    // MST will have size v-1, hence v-1 iterations
    int n_iter = 0, i = 0;
    while (n_iter < v - 1)
    {

        int ancestor1 = returnOldestAncestor(parent, input[i].source);
        int ancestor2 = returnOldestAncestor(parent, input[i].destination);
        // If sharing the same ancestor, discard edge and move on
        if (ancestor1 == ancestor2)
        {
            ++i;
            continue;
        }

        // Else, add edge in the MST array and update parents
        MST[n_iter] = input[i];
        ++i;
        ++n_iter;
        parent[ancestor2] = ancestor1;
    }

    return MST;
}
int main()
{
    int v, e;
    cout << "Enter number of vertices and edges in the graph\n";
    cin >> v >> e;
    Edge *input = new Edge[e]; // for storing the input graph as edges having two vertices and a weight
    cout << "Enter the edges as -> vertex_1 vertex_2 weight\n";
    for (int i = 0; i < e; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        input[i].setParameters(v1, v2, w);
    }

    Edge *MST = Kruskals(input, v, e);
    cout << "The MST is -->\n";

    // As MST will have v-1 edges
    for (int i = 0; i < v - 1; ++i)
    {
        int v1 = MST[i].source;
        int v2 = MST[i].destination;
        int weight = MST[i].weight;
        cout << min(v1, v2) << " " << max(v1, v2) << " " << weight << endl;
    }
}

/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5
*/