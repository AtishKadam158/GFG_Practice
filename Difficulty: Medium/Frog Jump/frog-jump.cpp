class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,0);
        dp[0]=0;
        if(n==1) return 0;
        dp[1]=abs(height[1]-height[0]);
        for(int i=2;i<n;i++){
            dp[i]=min(abs(height[i-1]-height[i])+dp[i-1] , abs(height[i-2]-height[i])+dp[i-2]);
        }
        return dp[n-1];
    }
};