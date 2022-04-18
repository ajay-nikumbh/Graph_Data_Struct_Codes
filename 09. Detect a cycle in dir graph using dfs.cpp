class Solution
{
  public:
    // Function to detect cycle in a directed graph.

    bool checkCycle(int node, vector<int> adj[], 
        vector<bool>&visited, vector<bool>&disvisited)
    {
        // Visited and disvisited make node true
        visited[node] = true;
        disvisited[node] = true;
    
        // Explore the nbrs
        for(auto i: adj[node])
        {
            
            if(!visited[i])
            {
                if(checkCycle(i, adj, visited, disvisited))
                    return true;
            }
            
            else if(disvisited[i])
                return true;
        }
        disvisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        // code here
        
        // Make 2 vector arrays
        vector<bool> visited(V, false);
        vector<bool> disvisited(V, false);
    
    
        // Explore all the components
        for(int i=0;i<V;i++)
        {
            // If not visited then call the method
            if(!visited[i])
            {
                if(checkCycle(i, adj, visited, disvisited))
                    return true;
            }
        }
        return false;
    }
};
