class Solution {
  public:
    int n;
    vector<vector<int>>memo;
    int help(int i,vector<int>& val, vector<int>& wt, int cap){
        if(i==0){
            if(cap>=wt[0]) return (cap/wt[0])*val[0];
            else return 0;
        }
        if(memo[i][cap] != -1 ) return memo[i][cap];
        int skip=help(i-1,val,wt,cap);
        int take=0;
        if(cap >= wt[i])
            take=val[i]+help(i,val,wt,cap-wt[i]);
        return memo[i][cap] =max(take,skip);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        n=val.size();
        memo.assign(n+1,vector<int>(capacity+1,-1));
        return help(n-1,val,wt,capacity);
    }
};