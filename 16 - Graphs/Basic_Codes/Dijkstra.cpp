#include <iostream>
#include <climits>

using namespace std;
void Dijkstra(int **edges, int v)
{
    bool *visited = new bool[v];
    int *pathCost = new int[v];
    int *previous = new int[v];

    // Taking 0 as starting vertex
    for (int i = 1; i < v; ++i)
    {
        pathCost[i] = INT_MAX;
        visited[i] = 0;
    }

    previous[0] = -1;
    pathCost[0] = 0;
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
                if (edges[current][i] + pathCost[current] < pathCost[i])
                {
                    pathCost[i] = edges[current][i] + pathCost[current];
                    previous[i] = current;
                }
            }
        }

        // For selection of lowest pathCosted - unvisited vertex
        int min_pos = 0, min_pathCost = INT_MAX;
        for (int i = 0; i < v; ++i)
        {
            if (min_pathCost > pathCost[i] && !visited[i])
            {
                min_pos = i;
                min_pathCost = pathCost[i];
            }
        }
        current = min_pos;
        ++n_iter;
    }

    // Diplaying vertex number and its distance/pathCost from the source vertex{taken as 0 here}
    for (int i = 0; i < v; ++i)
    {
        cout << i << " " << pathCost[i] << endl;
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
        int first, second, pathCost;
        cin >> first >> second >> pathCost;
        edges[first][second] = pathCost;
        edges[second][first] = pathCost;
    }

    Dijkstra(edges, v);

    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}

/*
Given an undirected, connected and pathCosted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with pathCost wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
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
0 0
1 3
2 4
3 5
*/