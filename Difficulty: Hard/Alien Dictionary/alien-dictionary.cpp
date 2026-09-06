class Solution {
public:

    bool create_DAG(vector<string>& words,
                    vector<vector<int>>& adj,
                    vector<int>& present) {

        int N = words.size();

        // Mark all characters that actually occur
        for (auto &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = 1;
            }
        }

        for (int i = 0; i < N - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            int ptr = 0;

            // Find first different character
            while (ptr < len && s1[ptr] == s2[ptr]) {
                ptr++;
            }

            // Prefix invalid case
            // Example: "abcd" before "abc"
            if (ptr == len && s1.size() > s2.size()) {
                return false;
            }

            // First different character gives the ordering
            if (ptr < len) {
                adj[s1[ptr] - 'a'].push_back(
                    s2[ptr] - 'a'
                );
            }
        }

        return true;
    }


    bool dfs(int i,
             vector<int>& visi,
             vector<int>& rec_st,
             vector<vector<int>>& adj,
             vector<int>& topo) {

        visi[i] = 1;
        rec_st[i] = 1;

        for (auto itr : adj[i]) {

            if (!visi[itr]) {

                if (dfs(itr, visi, rec_st, adj, topo)) {
                    return true;
                }
            }

            else if (rec_st[itr] == 1) {
                return true;
            }
        }

        // Finished processing this node
        rec_st[i] = 0;

        topo.push_back(i);

        return false;
    }


    string findOrder(vector<string>& words) {

        vector<vector<int>> adj(26);

        vector<int> present(26, 0);

        // Create graph
        if (!create_DAG(words, adj, present)) {
            return "";
        }

        vector<int> visi(26, 0);
        vector<int> rec_st(26, 0);

        vector<int> topo;

        // DFS only for characters present in words
        for (int i = 0; i < 26; i++) {

            if (present[i] && !visi[i]) {

                if (dfs(i, visi, rec_st, adj, topo)) {
                    return "";
                }
            }
        }

        // DFS finishing order is reversed
        reverse(topo.begin(), topo.end());

        string ans;

        for (auto x : topo) {
            ans += char(x + 'a');
        }

        return ans;
    }
};