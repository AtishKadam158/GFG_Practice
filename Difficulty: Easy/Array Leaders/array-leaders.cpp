

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n=arr.size();
        int max_r=-1;
        vector<int>res;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=max_r){
                max_r=arr[i];
                res.push_back(arr[i]);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};