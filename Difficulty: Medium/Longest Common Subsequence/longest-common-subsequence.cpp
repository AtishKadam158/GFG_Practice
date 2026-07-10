class Solution {
  public:
    vector<vector<int>>memo;
    int solve(int m,string &s1,int n,string &s2){
        if(m<0 || n<0)
            return 0;
            
        if(memo[m][n] != -1)
            return memo[m][n];
        if(s1[m]==s2[n])
            return memo[m][n]=1+solve(m-1,s1,n-1,s2);
        else 
            return memo[m][n]=max(solve(m,s1,n-1,s2),solve(m-1,s1,n,s2));
        
    }
    int lcs(string &s1, string &s2) {
        int m=s1.size()-1;
        int n=s2.size()-1;
        memo.assign(m+1,vector<int>(n+1,-1));
        return solve(m,s1,n,s2);
    }
};
