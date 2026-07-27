class Solution {
  vector<int>visi;
  vector<vector<int>>list_all;
  public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&temp){
        temp.push_back(node);
        visi[node]=1;
        
        for(auto itr : adj[node]){
            if(!visi[itr]){
                dfs(itr,adj,temp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        visi.assign(V,0);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int x=edges[i][0];
            int y=edges[i][1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        for(int i=0;i<V;i++){
            if(!visi[i]){
                vector<int>temp;
                dfs(i,adj,temp);
                list_all.push_back(temp);
            }
        }
        return list_all;
    }
};
