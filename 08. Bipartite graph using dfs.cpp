class Solution
{
public:

    bool bipartitate_check(int src,vector<int> adj[], vector<int> &color )
    {
        // If the color of src == -1 color it
        if(color[src] == -1) color[src] =1;
        
        // Travel through it's nbrs
        for(auto it: adj[src])
        {
            // If the color == -1 of it's nbrs then color
            if(color[it] == -1)
            {
                color[it] = 1- color[src];
                
                // Call the dfs again
                if(!bipartitate_check(it, adj, color))
                return false;
            }
            
            // If the color of src and nbr is same return false
            else if(color[it] == color[src]) return false;
        }
        
        // Return true if different color
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