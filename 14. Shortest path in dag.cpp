#include <bits/stdc++.h>
using namespace std;

void find_topo(int node , int vis[], stack<int> &s, vector<pair<int, int>> adj[])
{
	vis[node] =1;
	for(auto it: adj[node])
	{
		if(!vis[it.first])
		{
			find_topo(it, vis, s, adj);
		}
	}
	s.push(node);

}

void shortest_path(int src, int n, vector<pair<int, int>> adj[])
{
	int visit[n]= {0};
	stack<int> s;

	for(int i=0;i<n;i++)
	{
		if(!visit[i])
		{
			find_topo(i, visit, s, adj);

		}
	}

	int dist[n];
	for(int i=0;i<n;i++)
	{
		dist[i] = 1e9;
	}
	dist[src] = 0;

	while(!s.empty())
	{
		int node= s.top();
		s.pop();

		if(dist[node] != INF)
		{
			for(auto it: adj[node])
			{
				if(dist[node]+ it.second < dist[it.first])
				{
					dist[it.first]  = dist[node] + it.second;
				}
			}
		}
	}

	for(int i=0 ;i< n ;i++)
	{
		(dist[i] == 1e9 )?cout<<"INF" : <<cout<<dist[i]<<" ";

	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector< <pair<int, int> > adj[n];

	for(int i=0;i<m;i++)
	{
		int u, v, wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v,wt});
	}	
	shortest_path(0, n ,adj);
	return 0;
}

 