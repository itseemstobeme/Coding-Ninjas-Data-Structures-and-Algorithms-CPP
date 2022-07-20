#include <iostream>

using namespace std;

void DFS_connected(int **edges, int v, int startVertex, bool *visited); // for connected graph
int islands(int **edges, int v, bool *visited);

int main()
{
    int v, e; // no of vertices (from 0 to v-1), edges
    cout << "Enter no of vertices and edges\n";
    cin >> v >> e;
    if (e == 0) // if no edges, simply print the vertices in order
    {
        for (int i = 0; i < v; ++i)
            cout << i << " ";
        return 0;
    }
    int **edges = new int *[v]; // Graph implementation via adjacency matrix

    // Initialization of edges[][] matrix
    for (int i = 0; i < v; ++i)
    {
        edges[i] = new int[v];
        // Initialize all edges[i][j] = 0, i.e., no edges initially
        for (int j = 0; j < v; ++j)
            edges[i][j] = 0;
    }

    cout << "Enter two vertices between which edges exist\n";

    for (int i = 0; i < e; ++i)
    {
        int first, second;
        cin >> first >> second;
        edges[first][second] = edges[second][first] = 1; // edge exists between two vertices
    }

    bool *visited = new bool[v]; // for marking the visited vertices
    for (int i = 0; i < v; ++i)  // initializiation of all vertices initially as unvisited
        visited[i] = false;

    cout << islands(edges, v, visited);

    // Deallocate memory
    for (int i = 0; i < v; ++i)
        delete[] edges[i];

    delete[] edges;
    delete[] visited;
}

int islands(int **edges, int v, bool *visited)
{
    int connected = 0;
    for (int i = 0; i < v; ++i)
    {
        if (!visited[i])
        {
            DFS_connected(edges, v, i, visited);
            ++connected;
        }
    }
    return connected;
}

void DFS_connected(int **edges, int v, int startVertex, bool *visited)
{
    visited[startVertex] = 1; // startVertex is now visited

    // Now do DFS for all unvisited vertices connected to startVertex using recursion
    for (int i = 0; i < v; ++i)
    {
        if (i == startVertex) // startVertex has already been explored
            continue;

        if (!visited[i] && edges[startVertex][i] == 1) // if edge exists between startVertex and ith vertex,
            DFS_connected(edges, v, i, visited);       // and ith vertex is unvisited, then do DFS for it
    }
}

/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1
*/