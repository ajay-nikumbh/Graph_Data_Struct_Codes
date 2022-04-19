void bfs(vector<int> adj[], int n , int src)
{
    // Make the distance array
    int dist[n];
    
    // Make the distance array element equal to infinity
    for(int i=0;i<n;i++)
    {
        dist[i] = INT_MIN;
        
    }
    
    // Make a queue
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    
    // Travel till Queue not empty
    while(!q.empty())
    {
        
        int node= q.front();
        q.pop();
        
        // Travel the nbrs
        while(auto nbrs: adj[node])
        {
            // If the node +1 dist < dist[nbrs]
            if(dist[node]+1 < dist[nbrs])
            {
                // Update the optimal path
                dist[nbrs] = dist[node]+1;
                q.push(nbrs);
                
            }
        }
        
    
    for(int i=0;i<n ;i++)
    {
        cout<<dist[i]<<" ";
    }
}
