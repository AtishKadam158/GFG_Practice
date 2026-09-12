class Solution {
  public:
    int n;
    vector<vector<int>>memo;
    int help(int i,vector<int> &val, vector<int> &wt,int w){
        if(i == 0){
            if(wt[0] <= w) return val[0];
            else return 0;
        }
        if(memo[i][w]!=-1) return memo[i][w];
        int skip=help(i-1,val,wt,w);
        int take=0;
        if(wt[i] <= w)
            take=val[i]+help(i-1,val,wt,w-wt[i]);
            
        return memo[i][w] = max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n=val.size();
        memo.assign(n+1,vector<int>(W+1,-1));
        return help(n-1,val,wt,W);
    }
};