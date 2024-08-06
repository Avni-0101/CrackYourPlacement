class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> bfs;
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        
        while(!q.empty())
        {
            int node = q.front();
            bfs.push_back(node);
            q.pop();
            
            for(auto adjNode:adj[node])
            {
                if(!vis[adjNode])
                {
                    q.push(adjNode);
                    vis[adjNode] = true;
                }
            }
            
        }
        
        return bfs;
        
    }
};