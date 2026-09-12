class Solution {
  public:
    int n;
    vector<vector<int>>memo;
    int help(int i,int target,vector<int>&arr){
        if(i < 0)
            return target==0;
        
        if(memo[i][target] != -1)
            return memo[i][target];
        int skip=help(i-1,target,arr);
        int take=0;
        if(arr[i] <= target)
            take=help(i-1,target-arr[i],arr);
            
        return memo[i][target] =take+skip;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        n=arr.size();
        memo.assign(n+1,vector<int>(target+1,-1));
        return help(n-1,target,arr);
        
    }
};