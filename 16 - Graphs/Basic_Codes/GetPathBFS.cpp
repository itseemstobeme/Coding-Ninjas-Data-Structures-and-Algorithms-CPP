#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// SEE APPROACH FROM GRAPHS - 1 . pdf
vector<int> *getpathBFS(int **edges, int v, int startVertex, int endVertex, bool *visited)
{
    vector<int> *path = NULL;

    if (edges[startVertex][endVertex] == 1)
    {
        path = new vector<int>;
        path->push_back(endVertex);
        path->push_back(startVertex);
        return path;
    }

    queue<int> pendingVertices;
    unordered_map<int, int> previousVertex; // to store 1->2 and 2->3 in map, ie, vertex from which some vertex was explored
    pendingVertices.push(startVertex);
    visited[startVertex] = 1;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        // Pushing all vertices connected to currentVertex in the queue
        for (int i = 0; i < v; ++i)
        {
            if (i == currentVertex)
                continue;

            if (!visited[i] && edges[i][currentVertex] == 1)
            {
                pendingVertices.push(i);
                visited[i] = 1;
                previousVertex[i] = currentVertex;
            }
            if (i == endVertex)     //Path exists as it been pushed into the queue
                break;
        }
        if (pendingVertices.back() == endVertex)
            break;
    }

    int search = endVertex;
    while (previousVertex.find(search) != previousVertex.end())
    {
        if (path == NULL)
            path = new vector<int>;
        path->push_back(search);
        search = previousVertex[search];
    }
    if (path->size() > 0)
        path->push_back(startVertex);

    return path;
}
// 7 7
// 0 1 0 2 2 6 1 3 2 4 3 5 5 4
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

    int startVertex, endVertex;
    cout << "Enter start and end vertex between which path needs to be found\n";
    cin >> startVertex >> endVertex;

    // For displaying path
    vector<int> *path = getpathBFS(edges, v, startVertex, endVertex, visited);
    if (path != NULL)
    {
        for (int i = 0; i < path->size(); ++i)
            cout << path->at(i) << " ";
    }

    // Deallocate memory
    for (int i = 0; i < v; ++i)
        delete[] edges[i];

    delete[] edges;
    delete[] visited;
}

/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
*/