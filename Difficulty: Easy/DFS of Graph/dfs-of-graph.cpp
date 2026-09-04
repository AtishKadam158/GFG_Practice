class Solution {
  public:
    vector<int>ans;
    void traverse(vector<vector<int>>& adj,vector<bool>&visi,int i){
        visi[i]=true;
        ans.push_back(i);
        for(auto itr : adj[i]){
            if(!visi[itr]){
                visi[itr]=true;
                traverse(adj,visi,itr);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();
        vector<bool> visi(V,false);
        for(int i=0;i<V;i++)
            if(!visi[i])
                traverse(adj,visi,i);
            
        return ans;
    }
};