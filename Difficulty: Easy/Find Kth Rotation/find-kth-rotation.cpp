class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int l=0,r=arr.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid] > arr[r])
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};
