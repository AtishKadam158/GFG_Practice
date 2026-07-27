class Solution {
  private:
    void dfs_traverse(int node,vector<vector<int>>& adj,vector<int>& visi,vector<int>& res){
        visi[node]=1;
        res.push_back(node);
        for(auto itr:adj[node]){
            if(!visi[itr]){
                dfs_traverse(itr,adj,visi,res);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int N=adj.size();
        vector<int>visi(N,0);
        vector<int>res;
        dfs_traverse(0,adj,visi,res);
        return res;
    }
};