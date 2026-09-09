class Solution {
  public:
    
    vector<int> primeFactors(int n) {
        // code here
        vector<int>prime;
        while(n%2==0){
            prime.push_back(2);
            n/=2;
        }
        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                prime.push_back(i);
                n=n/i;
            }
        }
        if(n>2) prime.push_back(n);
        
        return prime;
    }
};
