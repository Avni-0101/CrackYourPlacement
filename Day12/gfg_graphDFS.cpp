// Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &order)
    {
        vis[node] = 1;
        order.push_back(node);
        
        for(auto adjNode : adj[node])
        {
            if(!vis[adjNode])
            {
                dfs(adjNode,adj,vis,order);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> order;
        
        dfs(0,adj,vis,order);
        
        return order;
    }