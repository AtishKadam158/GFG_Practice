class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int n=edges.size();
        vector<int>dist(V,1e8);
        
        dist[src]=0;
        for(int j=1;j<V;j++){
            for(int i=0;i<n;i++){
                if(dist[edges[i][0]] != 1e8 && dist[edges[i][0]] + edges[i][2] <  dist[edges[i][1]])
                    dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
            }
        }
        for(int i=0;i<n;i++){
                if(dist[edges[i][0]] != 1e8 && dist[edges[i][0]] + edges[i][2] <  dist[edges[i][1]])
                    return {-1};
            }
        return dist;
    }
};
