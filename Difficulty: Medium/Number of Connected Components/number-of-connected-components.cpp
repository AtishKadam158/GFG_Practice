class Solution {
  public:
    void traverse(int i,vector<int>&visi,vector<vector<int>>& adj){
        queue<int>q;
        q.push(i);
        visi[i]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto itr:adj[temp]){
                if(!visi[itr]){
                    q.push(itr);
                    visi[itr]=1;
                }
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
                traverse(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};