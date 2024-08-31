bool dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& recStack) 
    {
        visited[node] = 1;
        recStack[node] = 1;
    
        for(auto neighbor : adj[node]) 
        {
            if(!visited[neighbor]) 
            {
                if(dfs(neighbor, adj, visited, recStack)) 
                    return true;
            }
            else if(recStack[neighbor]) 
            {
                return true;
            }
        }
    
        recStack[node] = 0; // Backtracking
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
    
        for(int i = 0; i < V; i++) 
        {
            if(!visited[i]) 
            {
                if(dfs(i, adj, visited, recStack)) 
                    return true;
            }
        }
        return false;
    }