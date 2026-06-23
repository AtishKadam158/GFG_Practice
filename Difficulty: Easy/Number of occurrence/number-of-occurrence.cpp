class Solution {
  public:
    int countFreq(vector<int>& arr, int x) {
        // code here
        int start=0,end=0;
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid] >= x)
                r=mid-1;
            else
                l=mid+1;
        }
        start = l;
        l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid] > x)
                r=mid-1;
            else
                l=mid+1;
        }
        end = l;
        return end-start;
    }
};
