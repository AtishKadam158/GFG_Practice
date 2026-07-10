class Solution {
  public:
    int n;
    vector<vector<int>>memo;
    int solve(vector<int>& val, vector<int>& wt, int cap,int ind){
        if(ind == n){
            return 0;
        }
        
        if(memo[ind][cap] != -1)
            return memo[ind][cap];
            
            
        int take=0;
        
        if(cap-wt[ind] >=0 )
            take=val[ind] + solve(val,wt,cap-wt[ind],ind);
            
        int skip=solve(val,wt,cap,ind+1);
        
        return memo[ind][cap]=max(take,skip);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        n=val.size();
        memo.assign(n,vector<int>(capacity+1,-1));
        return solve(val,wt,capacity,0);
    }
};