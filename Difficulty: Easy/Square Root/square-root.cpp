class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l=1,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            int temp=mid*mid;
            if(temp == n)
                return mid;
            else if(temp > n)
                r=mid-1;
            else
                l=mid+1;
        }
        return r;
    }
};