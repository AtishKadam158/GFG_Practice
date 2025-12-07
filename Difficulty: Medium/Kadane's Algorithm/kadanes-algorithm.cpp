class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int max_sum=INT_MIN,sum=0;
        for(auto itr:arr){
            if(sum<=0)
                sum=0;
            sum+=itr;
            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};