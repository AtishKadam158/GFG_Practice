class Solution {
  public:
    void convert(vector<vector<int>> &adj,vector<vector<int>> &edges){
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
        }
    }
    void dfs(int i,vector<int>&visi,vector<int>&topo,vector<vector<int>>& adj){
        visi[i]=1;
        for(auto itr : adj[i]){
            if(!visi[itr]){
                dfs(itr,visi,topo,adj);
            }
        }
        topo.push_back(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        convert(adj,edges);
        
        vector<int>visi(V,0);
        vector<int>topo;
        
        for(int i=0;i<V;i++){
            if(!visi[i])
                dfs(i,visi,topo,adj);
        }
        reverse(topo.begin(),topo.end());
        return topo;
    }
};