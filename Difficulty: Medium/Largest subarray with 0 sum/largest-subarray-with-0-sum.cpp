class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        map<long long, int>mp;
        int n=arr.size();
        int i=0;
        int max_len=0;
        long long sum=0;
        while(i<n){
            sum+=arr[i];
            if(sum==0)
                max_len=max(max_len,i+1);
            int temp=sum;
            if(mp.count(temp))
                max_len=max(max_len,i-mp[temp]);
            
            if(!mp.count(sum))
                mp[sum]=i;
            i++;
        }
        return max_len;
    }
};