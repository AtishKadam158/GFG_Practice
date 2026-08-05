class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<pair<pair<int,int>,int>>vc;
        int n=s.size();
        for(int i=0;i<n;i++){
            vc.push_back({{f[i], s[i]}, i + 1});
        }
        sort(vc.begin(), vc.end(), [](auto &a, auto &b) {
            if (a.first.first == b.first.first)
                return a.second < b.second;
            return a.first.first < b.first.first;
        });
        vector<int> res;
        res.push_back(vc[0].second);
        int i = 0;
        for (int j=1;j<n;j++) {
            if (vc[j].first.second > vc[i].first.first) {
                res.push_back(vc[j].second);
                i = j;
            }
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};