class Solution {
  public:
    vector<vector<int>>memo;
    int help(int i,int target, vector<int>&arr){
        if(i<0) return target==0;
        
        if(memo[i][target] != -1)
            return memo[i][target];
        int skip=help(i-1,target,arr);
        int take=0;
        if(target >= arr[i])
            take=help(i-1,target-arr[i],arr);
            
        return memo[i][target] = take+skip;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n=arr.size();
        long long sum=0;
        for(auto itr:arr) sum+=itr;
        
        int target = (sum - diff);
        if (target < 0 || target % 2 != 0) return 0; 
        target /= 2;
        memo.assign(n+1,vector<int>(target+1,-1));
        return help(n-1,target,arr);
    }
};