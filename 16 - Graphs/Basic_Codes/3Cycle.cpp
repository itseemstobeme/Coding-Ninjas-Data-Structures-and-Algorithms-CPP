#include <iostream>
using namespace std;

int count3Cycle(int **edges, int v);

int main()
{
    int v, e;
    cin >> v >> e;
    if (e == 0)
    {
        cout << 0;
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
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    cout << count3Cycle(edges, v);
    for (int i = 0; i < v; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}

int count3Cycle(int **edges, int v)
{
    int count = 0;
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            if (edges[i][j] == 1) // if edge exists between nodes i & j
            {
                for (int k = 0; k < v; ++k)
                {
                    if (edges[j][k] == 1 && edges[i][k] == 1) // if edge exists between nodes j,k & i,k
                        ++count;                              // forming a 3 cycle(edge already exists between i & j)
                }
            }
        }
    }

    // Each vertex{say V1 as i} in 3 cycle will contribute to 2 cycles ->
    // one with V2 as j and V3 as k(clockwise)
    // and one with V3 as j and V2 as k(anticlockwise) , as no visited[] array is used
    // Three vertices in a cycle will contribute 2 cycles each, hence total no of cycles counted = 3 * 2 = 6
    // Effective(Actual) cycle = 6 / 6 = 1, ie, count/6
    return count / 6;
}
/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v.
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
*/