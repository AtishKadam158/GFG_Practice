class Solution {
  public:
    void convert(vector<vector<int>>& edges,vector<vector<int>>& adj){
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        convert(edges,adj);
        vector<int>visi(V,0);
        for(int i=0;i<V;i++){
            if(!visi[i]){
                queue<pair<int,int>>q;
                q.push({i,-1});
                visi[i] = 1;
                while(!q.empty()){
                    pair<int,int>temp=q.front();
                    q.pop();
                    int curr=temp.first;
                    int parent=temp.second;
                    for(auto itr:adj[curr]){
                        if(!visi[itr]){
                            q.push({itr,curr});
                            visi[itr]=1;
                        }else if(itr != parent)
                            return true;
                    }
                }
            }
        }
        return false;
        
    }
};