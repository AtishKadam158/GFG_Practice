class Solution {
  public:
    void convert(vector<vector<int>> &adj,vector<vector<int>> &edges){
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
        }
    }
    bool dfs(int i,vector<int>&visi,vector<int>&rec_st,vector<vector<int>>&adj){
        visi[i]=1;
        rec_st[i]=1;
        for(auto itr:adj[i]){
            if(!visi[itr]){
                if(dfs(itr,visi,rec_st,adj))
                    return true;
            }else if(rec_st[itr])
                return true;
        }
        rec_st[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        convert(adj,edges);
        vector<int>visi(V,0);
        vector<int>rec_st(V,0);
        for(int i=0;i<V;i++){
            if(!visi[i])
                if(dfs(i,visi,rec_st,adj))
                    return true;
            
        }
        return false;
    }
};