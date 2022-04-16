#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Declare the no of vertices and edges
	int vertices, edges;

	// Input the vertices & edges
	cin>>vertices >>edges;

	// Declare the adj_matrix
	int adj_matrix[n+1][n+1];

	// Iterate over the edges and connect the edges
	for(int i=0;i<edges;i++)
	{
		// Input the edge1 and edge 2
		int edge1, edge2;
		cin>>edge1>>edge2;

		// In adj matrix mark 1 if 2 edges are connected
		adj_matrix[u][v] = 1;
		adj_matrix[v][u] =1;
	}
	return 0;
}