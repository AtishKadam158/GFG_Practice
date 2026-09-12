class Solution {
  public:
    int n;
    vector<vector<int>>memo;
    int help(int i,int len,vector<int>&price){
        if(i==0)
            return len * price[0];
        
        if(memo[i][len] != -1) return memo[i][len];
        int skip=help(i-1,len,price);
        int take=0;
        if(len >= i+1)
            take=price[i]+help(i,len-(i+1),price);
            
        return memo[i][len]=max(skip,take);
    }
    int cutRod(vector<int> &price) {
        // code here
        n=price.size();
        memo.assign(n,vector<int>(n+1,-1));
        return help(n-1,n,price);
    }
};