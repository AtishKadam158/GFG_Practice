class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int zero=0,two=0,one=0;
        for(auto itr:arr){
            if(itr==1)
                one++;
            else if (itr==0)
                zero++;
            else
                two++;
        }
        int n=arr.size(),i=0;
        while(zero--)
            arr[i++]=0;
        while(one--)
            arr[i++]=1;
        while(two--)
            arr[i++]=2;
        
    }
};