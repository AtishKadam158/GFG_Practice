class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n=arr.size();
        long long sum=(n+1)*(n+2)/2;
        for(auto itr: arr)
            sum-=itr;
        return sum;
    }
};