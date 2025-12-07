class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        map<int,int>mp;
        vector<int>repeated_elements;
        for(auto itr:arr)
            mp[itr]++;
        for(auto itr:mp){
            if(itr.second>1)
                repeated_elements.push_back(itr.first);
        }
        return repeated_elements;
    }
};