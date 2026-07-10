class Solution {
  public:
    int ans=0;
    vector<vector<int>>memo;
    int solve(int m,string& s1, int n, string& s2){
        if(m<0 || n<0)
            return 0;
        
        if(memo[m][n]!=-1) return memo[m][n];
        
        int curr=0;
        if(s1[m]==s2[n]){
            curr=1+solve(m-1,s1,n-1,s2);
            ans=max(curr,ans);
            memo[m][n]=ans;
        }
      
        solve(m-1,s1,n,s2);
        solve(m,s1,n-1,s2);
        
        return memo[m][n]=curr;
    }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m=s1.size();
        int n=s2.size();
        memo.assign(m+1,vector<int>(n+1,-1));
        solve(m-1,s1,n-1,s2);
        return ans;
    }
};