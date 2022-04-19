class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        // Make a priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair
        <int, int>>> pq;
        
        // Make a distance array and make it's vals as infinity
        vector<int> distance(v+1, INT_MAX);
        
        // Make the src distance =0
        distance[s]= 0;
        
        // Push the wt + src in priority queue
        pq.push({0,s});
        
        // Explore till queue not empty
        while(!pq.empty())
        {
            
            int dist= pq.top().first;
            int prev= pq.top().second;
            pq.pop();
            
            for(auto it: adj[prev])
            {
                // Update the distance 
                if(distance[it[0]] > distance[prev]+ it[1])
                {
                    distance[it[0]] = distance[prev]+ it[1];
                    pq.push({distance[it[0]] , it[0]});
                }
            }
        }
        return distance;
    }
};