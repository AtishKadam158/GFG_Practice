class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n=arr.size()+1;
        long long sum=n*(n+1)/2;
        for(auto itr : arr)
            sum-=itr;
        return (int)sum;
    } 
};