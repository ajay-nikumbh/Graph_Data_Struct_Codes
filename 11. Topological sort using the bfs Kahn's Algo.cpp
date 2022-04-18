class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
        
        //Make a vector for indegree and mark it 0
        vector<int> indegree(v,0);
        
        // Decalrea queue
        queue<int> q;
        
        // Count the indegree's
        for(int i=0;i<v;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
        // Check and push the node if indegree is 0
        for(int i=0;i<v;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        // Create an ans array for stroing the final result
        vector<int> ans;
        
        // Travel the queue till not empty
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            ans.push_back(node);
            
            // Travel its nbrs
            for(auto it: adj[node])
            {
                // Reduce the indegree by 1
                indegree[it]--;
                
                // If the indegree ==0 then push into Queue
                if(indegree[it] ==0)
                {
                    q.push(it);
                    
                }
            }
            
        }
        // Return the final ans
        return ans;
	}
};