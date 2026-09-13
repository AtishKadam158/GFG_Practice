class Solution {
  public:
    int n,m;
    vector<vector<int>>memo;
    int solve(int i,int j,string &s1, string &s2){
        if(i==0 || j==0)
            return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(s1[i-1]==s2[j-1])
            return memo[i][j] = 1+solve(i-1,j-1,s1,s2);
            
        return memo[i][j] = max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
    }
    int lcs(string &s1, string &s2) {
        // code here
        n=s1.size();
        m=s2.size();
        memo.assign(n+1,vector<int>(m+1,-1));
        return solve(n,m,s1,s2);
    }
};
