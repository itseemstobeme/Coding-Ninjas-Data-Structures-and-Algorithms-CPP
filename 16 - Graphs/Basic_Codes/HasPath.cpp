#include <iostream>

using namespace std;

bool hasPath(int **edges, int v, int startVertex, int endVertex, bool *visited)
{
    visited[startVertex] = 1;
    if (edges[startVertex][endVertex] == 1) // edge exists
        return 1;

    bool ans = 0;
    for (int i = 0; i < v; ++i)
    {
        if(i == startVertex)    //exploring vertex same as starting vertex
            continue;

        if(!visited[i] && edges[startVertex][i] == 1)
            ans = hasPath(edges,v,i,endVertex,visited);
        
        if(ans == 1)
            return true;
    }

    return ans; //it will be false if code reaches till this point
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

    // For displaying existebce of path
    if (hasPath(edges, v, startVertex, endVertex, visited))
        cout << "true";
    else
        cout << "false";

    // Deallocate memory
    for (int i = 0; i < v; ++i)
        delete[] edges[i];

    delete[] edges;
    delete[] visited;
}
/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false
*/