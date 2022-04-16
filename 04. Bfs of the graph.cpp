class Solution
{
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) 
    {
        // Make bfs vector for the final ans
        vector<int> bfs;
        
        // Make the visited array
        vector<int> visited(v, false);
        
        // Create the queue
        queue<int> q;
        
        // Push the first node in the queue
        q.push(0);
        
        // Travel the queue till not empty
        while(!q.empty())
        {
            
            // Current node 
            int curr= q.front();
            
            // Pop that node
            q.pop();
            
            // If current node visited then continue with the next node
            if(visited[curr]) continue;
            
            // Make the node as visited
            visited[curr] = true;
            
            // Push that node in the final result
            bfs.push_back(curr);
            
            // Travel adj nodes of the current
            for(auto it: adj[curr])
            {
                
                q.push(it);
            }
            
        }
        
        return bfs;
    }
};
