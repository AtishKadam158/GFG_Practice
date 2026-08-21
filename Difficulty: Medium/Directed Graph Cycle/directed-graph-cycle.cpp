class Solution {
  public:
    void convert(vector<vector<int>> &adj,vector<vector<int>> &edges){
        for(auto itr : edges)
            adj[itr[0]].push_back(itr[1]);
    }
    bool dfs(int i,vector<vector<int>> &adj,vector<int>&vis,vector<int>&pathvis){
        vis[i] = 1;
        pathvis[i] = 1;
        for (auto itr : adj[i]) {
            if (!vis[itr]) {
                if (dfs(itr, adj, vis, pathvis))
                    return true;
            }
            else if (pathvis[itr]) 
                return true; 
        }
        pathvis[i] = 0; 
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        convert(adj,edges);
        
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis))
                    return true;
            }
        }
        return false;
    }
};