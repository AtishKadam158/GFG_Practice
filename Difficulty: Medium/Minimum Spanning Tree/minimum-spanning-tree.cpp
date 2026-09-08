class DisjointSet {
    vector<int> parent;
    vector<int> rank;
public:
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
    int spanningTree(int V, vector<vector<int>>& edges) {
        DisjointSet ds(V);
        vector<pair<int, pair<int, int>>> adj;
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj.push_back({wt, {u, v}});
        }
        sort(adj.begin(), adj.end());
        int mstWt = 0;
        for(auto it : adj) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.find(u) != ds.find(v)) {
                mstWt += wt;
                ds.unionByRank(u, v);
            }
        }
        return mstWt;
    }
};