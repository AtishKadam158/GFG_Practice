class Solution {
  public:
    void convert(vector<vector<int>> &edges,vector<vector<int>> &adj){
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
    }
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>>adj(V);
        convert(edges,adj);
        vector<int>visi(V,0);
        
        queue<pair<int,int>>q;
        q.push({src,0});
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int>p=q.front();
                q.pop();
                int node=p.first;
                int dst=p.second;
                for(auto itr:adj[node]){
                    if(itr == dest) return dst+1;
                    if(!visi[itr]) q.push({itr,dst+1}),visi[itr]=1;
                }
            }
        }
        return -1;
    }
};
