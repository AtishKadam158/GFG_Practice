class Solution {
  public:
    int count_one(vector<int>&num){
        int r=num.size()-1;
        int l=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(num[mid]==1){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return num.size()-1-l;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int ind=-1,max_one=0;
        for(int i=0;i<n;i++){
            int temp=count_one(arr[i]);
            if(temp > max_one){
                max_one=temp;
                ind=i;
            }
        }
        return ind;
    }
};