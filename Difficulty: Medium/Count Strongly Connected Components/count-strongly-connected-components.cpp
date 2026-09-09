class Solution {
  private:
    void dfs(int i,vector<int> &visi,vector<vector<int>> &adj,stack<int>&st){
        visi[i]=1;
        for(auto itr:adj[i]){
            if(!visi[itr]){
                dfs(itr,visi,adj,st);
            }
        }
        st.push(i);
    }
  private: 
    void dfs3(int i,vector<int> &visi,vector<vector<int>> &adj){
        visi[i]=1;
        for(auto itr:adj[i]){
            if(!visi[itr]){
                dfs3(itr,visi,adj);
            }
        }
    }
  public:
    int countSCC(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>visi(V,0);
        vector<vector<int>>adj(V);
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
        }
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!visi[i]){
                dfs(i,visi,adj,st);
            }
        }
        // transpose
        vector<vector<int>>adj2(V);
        for(int i=0;i<V;i++){
            for(auto itr:adj[i]){
                adj2[itr].push_back(i);
            }
            
        }
        vector<int>visi2(V,0);
        int count=0;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            if(!visi2[temp]){
                dfs3(temp,visi2,adj2);
                count++;
            }
        }
        return count;
    }
};