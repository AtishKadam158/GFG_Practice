class Solution {
  public:
    void dfs(int i,vector<int>&visi,vector<vector<int>>& adj){
        visi[i]=1;
        for(auto itr : adj[i]){
            if(!visi[itr]){
                dfs(itr,visi,adj);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>visited(V,0);
        
        vector<vector<int>>adj(V);
        int N=edges.size();
        for(int i=0;i<N;i++){
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};