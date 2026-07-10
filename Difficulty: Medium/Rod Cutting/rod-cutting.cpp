class Solution {
  public:
    vector<vector<int>>memo;
    int n;
    int solve(vector<int> &price,int ind, int sz){
        if(ind == n || sz==0)
            return 0;
        if(memo[ind][sz]!=-1)   return memo[ind][sz];
        int take=0;
        if(sz >= ind+1)
            take=price[ind] + solve(price,ind,sz-ind-1);
        int skip=solve(price,ind+1,sz);
        return memo[ind][sz]=max(take,skip);
    }
    int cutRod(vector<int> &price) {
        // code here
        n=price.size();
        memo.assign(n,vector<int>(n+1,-1));
        return solve(price,0,n);
    }
};