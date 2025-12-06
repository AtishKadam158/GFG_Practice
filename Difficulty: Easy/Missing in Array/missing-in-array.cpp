class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long int sum=0;
        long long int n=arr.size()+1;
        long long int total = n*(n+1)/2;
        for(auto itr:arr){
            sum+=itr;
        }
        return total - sum;
    }
};