class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int N=adj.size();
        vector<int>visi(N,0);
        vector<int>bfs;
        queue<int>q;
        q.push(0);
        visi[0]=1;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            bfs.push_back(temp);
            for(auto itr:adj[temp]){
                if(!visi[itr]){
                    q.push(itr);
                    visi[itr]=1;
                }
            }
            
        }
        return bfs;
    }
};