class Solution {
  public:
    void convert(vector<vector<int>>& edges,vector<vector<int>>& adj){
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
    }
    bool dfs(int curr,int parent,vector<vector<int>>& adj,vector<int>&visi){
        visi[curr]=1;
        
        for(auto itr:adj[curr]){
            if(!visi[itr]){
                if (dfs(itr, curr,adj, visi))
                    return true;
            }else if(itr != parent)
                return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        convert(edges,adj);
        
        vector<int>visi(V,0);
        
        for(int i=0;i<V;i++){
            if(!visi[i]){
                pair<int,int> temp={i,-1};
                if(dfs(i,-1,adj,visi))
                    return true;
            }
        }
        return false;
    }
};