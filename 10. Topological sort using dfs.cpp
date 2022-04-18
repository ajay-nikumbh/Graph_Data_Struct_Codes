class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs_topo(int node, vector<int> adj[], vector<int> &visited, 
	                stack<int> &s)
	{
        // Mark the current node as a visited
	    visited[node] =1;
	    
	    // Explore the nbrs of the current node
	    for(auto nbrs: adj[node])
	    {
	        if(!visited[nbrs])
	        {
	            dfs_topo(nbrs, adj,visited, s);
	  
	        }
	    }
	    
	    // Push the node into stack
	    s.push(node);
	    
	}
	
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    
	    // Create the visited array
	    vector<int> visited(v,0);
	    
	    // Create the stack 
	    stack<int> s;
	    
	    // Explore for all the components
	    for(int i=0;i<v;i++)
	    {
	        // If not visited then call dfs_topo
	        if(!visited[i])
	        {
	            dfs_topo(i, adj, visited, s);
	        }
	    }
	    
	    // Create a array for storing fianl results
	    vector<int> topo_result;
	    
	    
	    while(!s.empty())
	    {
	        topo_result.push_back(s.top());
	        s.pop();
	    }
	    
	    // Return final result
	    return topo_result;
	}
};
