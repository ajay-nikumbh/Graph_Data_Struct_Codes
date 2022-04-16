#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Declare the no of vertices and edges
	int vertices, edges;

	// Input the vertices & edges
	cin>>vertices >>edges;

	// Declare the adj_list
	vector<int> adj_list[n+1];

	// Iterate over the edges and connect the edges
	for(int i=0;i<edges;i++)
	{
		// Input the edge1 and edge 2
		int edge1, edge2;
		cin>>edge1>>edge2;

		// In adj matrix mark 1 if 2 edges are connected
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	return 0;
}