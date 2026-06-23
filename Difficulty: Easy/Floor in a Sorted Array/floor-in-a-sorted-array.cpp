class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]>x){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return r;
    }
};
