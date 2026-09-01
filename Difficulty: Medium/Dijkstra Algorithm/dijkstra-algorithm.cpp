class Solution {
  public:
    void convert(vector<vector<int>> &edges, vector<vector<pair<int,int>>>&adj){
        for(auto itr:edges){
            adj[itr[0]].push_back({itr[1],itr[2]});
            adj[itr[1]].push_back({itr[0],itr[2]});
        }
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        convert(edges,adj);
        vector<int>dist(V,INT_MAX);
        
        dist[src]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({dist[src],src});
        
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int dst=p.first;
            int node=p.second;
            if(dst > dist[node])
                continue;
            for(auto itr : adj[node]){
                int adj_node=itr.first;
                int edge_wt=itr.second;
                if(dst+edge_wt < dist[adj_node]){
                    dist[adj_node]=dst+edge_wt;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        return dist;
    }
};