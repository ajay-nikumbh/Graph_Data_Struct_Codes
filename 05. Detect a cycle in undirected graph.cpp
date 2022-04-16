class Solution 
{
  public:

    bool check_for_cycle(int s,int v, vector<int> adj[], vector<int> &visited )
    {
        // Create the queue
        queue<pair<int, int>> q;
        
        // Mark current node s as visited
        visited[s] = true;
        
        // Push the first node and it's parent as -1
        q.push({s,-1});
        
        // Travel queue till not empty
        while(!q.empty())
        {
            // Q.front.first = node
            int node= q.front().first;
            
            // Q.front.second = parent
            int parent= q.front().second;
            
            // Pop that node
            q.pop();
            
            // Now travel it's adj nodes
            for(int it: adj[node])
            {
                
                // Enter only if it's not visited
                if(!visited[it])
                {
                    // Make that node as visited
                    visited[it] = true;
                    
                    // Push that node into queue
                    q.push({it, node});
                    
                }
                
                // Return true if parent is not it
                else if(parent !=it)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int v, vector<int> adj[]) 
    {
        
        // Make a visited array 
        vector<int> visited(v+1,0);
        
        // Travel through each component
        for(int i=0;i<v;i++)
        {
            // If that node is not being visited
            if(!visited[i])
            {
                // Call the function for detecting the cycle
                if(check_for_cycle(i, v, adj, visited)) return true;
                
            }
        }
        return false;
    }
};