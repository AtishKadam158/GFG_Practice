class Solution {
  public:
    bool subset_sum(vector<int>& arr,int target,int curr,int curr_sum){
        if(curr_sum==target)
            return true;
            
        if(curr>=arr.size() || curr_sum > target)
            return false;
        
        return subset_sum(arr,target,curr+1,curr_sum+arr[curr]) || 
        subset_sum(arr,target,curr+1,curr_sum);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return subset_sum(arr,sum,0,0);
    }
};