class Solution {
  public:
    bool isKSortedArray(vector<int>& arr, int k) {
        // code here.
        vector<int>temp;
        temp=arr;
        sort(temp.begin(),temp.end());
        map<int,int>mp;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            mp[temp[i]]=i;
        }
        
        for(int i=0;i<n;i++){
            if(abs(i-mp[arr[i]]) > k)
                return false;
        }
        
        return true;
    }
};
