class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l=1;
        int r=m;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long temp=pow(mid,n);
            if(temp==m){
                return mid;
            }else if(temp > m){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return pow(r,n)==m ? r : -1;
    }
};