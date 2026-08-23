class Solution {
  public:
    vector<int>res;
    
    void dfs(int i, vector<vector<int>>& adj,vector<int> &vis){
        vis[i]=1;
        for(auto itr : adj[i]){
            if(!vis[itr])
                dfs(itr,adj,vis);
        }
        res.push_back(i);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
        }
        
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i,adj,vis);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};