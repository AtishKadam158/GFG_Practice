class Solution {
  public:
    vector<vector<int>>compo;
    void convert(vector<vector<int>>& edges,vector<vector<int>>& adj){
        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
    }
    void dfs(vector<int>&visi,vector<vector<int>>&adj,int i,vector<int>&temp){
        visi[i]=1;
        temp.push_back(i);
        for(auto itr:adj[i]){
            if(!visi[itr]){
                visi[itr]=1;
                dfs(visi,adj,itr,temp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<int>visi(V,0);
        convert(edges,adj);
        
        for(int i=0;i<V;i++){
            if(visi[i]==0){
                vector<int>temp;
                dfs(visi,adj,i,temp);
                compo.push_back(temp);
            }
        }
        return compo;
        
    }
};
