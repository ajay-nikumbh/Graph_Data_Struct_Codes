class Solution 
{
  public:
    bool dfs(vector<int> adj[], vector<bool>& vis, int source, int parent)
    {
        // Make the src as visited
        vis[source] = true;
        
        // Travel through it's adj nodes
        for(auto u : adj[source])
        {
            // If visited is false then call the dfs
            if(vis[u] == false)
            {
                // If dfs found the same nodes visited then mark true 
                if(dfs(adj, vis, u, source))
                {
                    return true;
                }
            }
            
            // If the node is visited and if node is ! to parent node 
            // then return true
            else if(u != parent)
            {
                return true;
            }
        }
        
        // Else return false
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[])
    {
    
        // Make the visited array    
        vector<bool> vis(V, false);
        
        // Travel through whole components
        for(int i = 0; i < V; i++)
        {
            // If not visited the call the dfs function
            if(vis[i] == false)
            {
                if(dfs(adj, vis, i, -1))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};