class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int>divisor;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divisor.push_back(i);
                if(i != n/i)
                    divisor.push_back(n/i);
            }
        }
        sort(divisor.begin(),divisor.end());
        return divisor;
    }
};