class Solution {
  public:
    vector<vector<int>>memo;
    bool subset_sum(vector<int>& arr,int target,int curr,int curr_sum){
        if(curr_sum==target)
            return true;
            
        if(curr>=arr.size() || curr_sum > target)
            return false;
        if(memo[curr][curr_sum]!=-1) return memo[curr][curr_sum];
        return memo[curr][curr_sum]=subset_sum(arr,target,curr+1,curr_sum+arr[curr]) 
        || subset_sum(arr,target,curr+1,curr_sum);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        memo.assign(n,vector<int>(sum+1,-1));
        return subset_sum(arr,sum,0,0);
    }
};