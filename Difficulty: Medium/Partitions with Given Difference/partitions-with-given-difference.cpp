class Solution {
  public:
    vector<vector<int>>memo;
    int n;
    int count_part(vector<int>& arr, int target, int curr, int curr_sum){
        if(curr==n)
            return (curr_sum == target);
            
        if(memo[curr][curr_sum]!=-1)
            return memo[curr][curr_sum];
        
        int x=0,y=0;
        if(curr_sum+arr[curr] <= target)
            x=count_part(arr,target,curr+1,curr_sum+arr[curr]);
        y=count_part(arr,target,curr+1,curr_sum);
        
        return memo[curr][curr_sum]=x+y;
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        n=arr.size();
        int target=0;
        for(auto itr: arr)
            target+=itr;
        if((target+diff) % 2 ==1)
            return 0;
        target=(target+diff)/2;
        memo.assign(n,vector<int>(target+1,-1));
        
        return count_part(arr,target,0,0);
    }
};