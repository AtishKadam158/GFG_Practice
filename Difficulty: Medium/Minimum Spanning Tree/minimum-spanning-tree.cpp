class Solution {
  public:
    void convert(vector<vector<int>>& edges, vector<vector<int>>& adj) {
        for(auto itr: edges){
            adj[itr[0]][itr[1]]=itr[2];
            adj[itr[1]][itr[0]]=itr[2];
        }
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V,vector<int>(V,INT_MAX));
        convert(edges,adj);
        
        for(int i=0;i<V;i++)
            adj[i][i]=0;
        
        int sum=0;
        vector<vector<int>>mst;
        vector<bool>visi(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty()){
            pair<int,int>tmp=pq.top();
            pq.pop();
            
            int node=tmp.second;
            int wt=tmp.first;
            
            if(visi[node])
                continue;
            
            visi[node]=1;
            sum+=wt;
            
            for(int i=0;i<V;i++)
                if(adj[node][i] != INT_MAX && !visi[i])
                    pq.push({adj[node][i], i});
                
        }
        return sum;
    }
};