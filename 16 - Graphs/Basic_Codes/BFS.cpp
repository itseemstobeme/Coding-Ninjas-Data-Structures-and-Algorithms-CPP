#include <iostream>
#include <queue>

using namespace std;

void BFS(int **edges, int v, int startVertex, bool *visited);           // for disconnected graph
void BFS_connected(int **edges, int v, int startVertex, bool *visited); // for connected graph

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

    int startVertex = 0;
    // cout << "Enter the starting vertex\n";
    // cin >> startVertex;
    BFS(edges, v, startVertex, visited);

    // Deallocate memory
    for (int i = 0; i < v; ++i)
        delete[] edges[i];

    delete[] edges;
    delete[] visited;
}

void BFS(int **edges, int v, int startVertex, bool *visited)
{
    BFS_connected(edges, v, startVertex, visited); // for connected graph starting with the startVertex

    // Now for all the unvisited vertices, i.e., the disconnected elements
    for (int i = 0; i < v; ++i)
    {
        if (!visited[i])
            BFS_connected(edges, v, i, visited); // if ith vertex is unvisited, start exploring it
    }
}

void BFS_connected(int **edges, int v, int startVertex, bool *visited)
{
    queue<int> pendingEdges; // all the unvisited vertices

    pendingEdges.push(startVertex);
    visited[startVertex] = true;

    while (!pendingEdges.empty())
    {
        int currentEdge = pendingEdges.front();
        pendingEdges.pop();
        cout << currentEdge << " ";

        // Now do BFS for all unvisited vertices connected to currentEdge using queue
        for (int i = 0; i < v; ++i)
        {
            if (i == currentEdge) // currentEdge has already been explored
                continue;

            if (!visited[i] && edges[currentEdge][i] == 1) // if edge exists between startVertex and ith vertex,
            {                                              // and ith vertex is unvisited, then do BFS for it
                pendingEdges.push(i);
                visited[i] = 1;
            }
        }
    }
}