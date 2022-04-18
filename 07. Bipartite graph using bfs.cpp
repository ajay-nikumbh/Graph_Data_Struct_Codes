class Solution
{
public:

    bool bipartitate_check(int src,vector<int> adj[], vector<int> &color )
    {
        // Make a queue
        queue<int> q;
        
        // Push the src node
        q.push(src);
        
        // Color the src node with 1
        color[src] =1;
        
        // Travel till queue not empty
        while(!q.empty())
        {
            // Extract the front node
            int node= q.front();
            q.pop();
            
            // Explore the nodes of the front node
            for(auto it: adj[node])
            {
                // If the nbrs color == -1 then color them 
                // with the different color
                if(color[it] == -1)
                {
                    
                    color[it] = 1- color[node];
                    q.push(it);
                }
                
                // If the scr node and curr node same color return false
                else if(color[it] == color[node]) return false;
                
            }
        }
        return true;
    }


	bool isBipartite(int v, vector<int>adj[])
	{
	    // Declare the color array
	    vector<int> color(v, -1);
	    
	    // Travel for each components
	    for(int i=0;i<v;i++)
	    {
	        // If the color[i] is -1 then call check bipartiate graph function 
	        if(color[i] == -1)
	        {
	            
	            if(!bipartitate_check(i,adj,color)) return false;
	        }
	    }
	    return true;
	}

};