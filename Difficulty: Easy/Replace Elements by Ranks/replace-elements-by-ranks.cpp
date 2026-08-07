class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]= {arr[i],i};
        }
        
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<n;i++)
            arr[temp[i].second] = i;
        
    }
};