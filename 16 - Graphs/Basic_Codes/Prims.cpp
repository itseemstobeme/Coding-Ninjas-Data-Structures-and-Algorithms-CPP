#include <iostream>
#include <climits>

using namespace std;
void Prims(int **edges, int v)
{
    bool *visited = new bool[v];
    int *weight = new int[v];
    int *parent = new int[v];

    // Taking 0 as starting vertex
    for (int i = 1; i < v; ++i)
    {
        weight[i] = INT_MAX;
        visited[i] = 0;
    }

    parent[0] = -1;
    weight[0] = 0;
    visited[0] = 0;

    // no of iterations, current vertex whose adjacent unvisited vertices are being explored
    int n_iter = 0, current = 0;

    while (n_iter < v - 1)
    {
        visited[current] = 1; // current visited has been visited, mark it

        // For exploration and updation of unvisited adjacent vertices
        for (int i = 0; i < v; ++i)
        {
            if (!visited[i] && edges[current][i] > 0) // if edge exists
            {
                if (edges[current][i] < weight[i])
                {
                    weight[i] = edges[current][i];
                    parent[i] = current;
                }
            }
        }

        // For selection of lowest weighted - unvisited vertex
        int min_pos = 0, min_weight = INT_MAX;
        for (int i = 0; i < v; ++i)
        {
            if (min_weight > weight[i] && !visited[i])
            {
                min_pos = i;
                min_weight = weight[i];
            }
        }
        current = min_pos;
        ++n_iter;
    }

    // Diplaying MST
    for (int i = 1; i < v; ++i)
    {
        int minimum = min(i, parent[i]);
        int maximum = max(i, parent[i]);
        cout << minimum << " " << maximum << " " << edges[i][parent[i]] << endl;
    }
}
int main()
{
    int v, e;
    cout << "Enter number of vertices and edges\n";
    cin >> v >> e;
    if (e == 0)
    {
        for (int i = 0; i < v; i++)
            cout << i << " ";
        return 0;
    }
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];

        for (int j = 0; j < v; j++)
            edges[i][j] = 0; // Giving default value as 0
    }

    for (int i = 0; i < e; i++)
    {
        int first, second, weight;
        cin >> first >> second >> weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }

    Prims(edges, v);

    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}

/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
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
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5
*/