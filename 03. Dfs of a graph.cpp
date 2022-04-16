class Solution 
{
  public:
  
    void dfs(vector<int> adj[], int i , vector<bool> &v)
    {
        // Print the current node
        
        cout<<i<<" ";
        
        // Mark that node as a visited
        v[i] = true;
        
        // Travel through it's nbrs
        for(auto nbr: adj[i])
        {
            // If nbrs not being visited then call dfs on that nbrs
            if(!v[nbr])
            {
                // Calling the dfs
                dfs(adj, nbr, v);
            }
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        // Make a visited array
        vector<bool> visit(v,false);
        
        // Travel through its components
        for(int i=0;i<v;i++)
        {
            // If that node in any compo not being visited that call the dfs 
            if(!visit[i])
            {
                dfs(adj, i, visit);
            }
        }
        return {};
    }    
};
