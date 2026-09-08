class DisjointSet {  
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b)
            return;
        if(rank[a] < rank[b])
            parent[a] = b;
        else if(rank[a] > rank[b])
            parent[b] = a;
        else{
            parent[b] = a;
            rank[a]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>visi(n,vector<int>(m,0));
        DisjointSet ds(n*m);
        
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int r=it[0];
            int c=it[1];
            if(visi[r][c]){
                ans.push_back(cnt);
                continue;
            }
            visi[r][c]=1;
            cnt++;
            int row[]={0,0,-1,1};
            int col[]={-1,1,0,0};
            
            for(int i=0;i<4;i++){
                int x=r+row[i];
                int y=c+col[i];
                if(x>=0 && y>=0 && x<n && y<m && visi[x][y]==1){
                    int node=r*m+c;
                    int adj=x*m+y;
                    if(ds.find(node)!=ds.find(adj)){
                        cnt--;
                        ds.unionByRank(node,adj);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};