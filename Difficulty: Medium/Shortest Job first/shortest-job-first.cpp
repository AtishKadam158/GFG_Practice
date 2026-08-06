class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int t=0;
        int wt=0;
        int n=bt.size();
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++){
            wt+=t;
            t+=bt[i];
        }
        return wt/n;
    }
};