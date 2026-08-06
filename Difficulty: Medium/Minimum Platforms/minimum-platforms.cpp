class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        int curr=0,max_plat=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                curr++;
                max_plat=max(curr,max_plat);
                i++;
            }else{
                curr--;
                j++;
            }
        }
        return max_plat;
    }
};
