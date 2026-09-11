class Solution {
  public:
    int n;
    vector<vector<bool>>memo;
    bool help(vector<int>& arr, int ind,int curr, int target){
        if (curr > target) return false;
        if(ind >= n){
            if(curr == target)
                return true;
            return false;
        }
        if(memo[ind][curr]) return memo[ind][curr];
        return memo[ind][curr] = help(arr,ind+1,curr+arr[ind],target) || help(arr,ind+1,curr,target);
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        n=arr.size();
        memo.assign(n+1,vector<bool>(sum+1,0));
        return help(arr,0,0,sum);
    }
};