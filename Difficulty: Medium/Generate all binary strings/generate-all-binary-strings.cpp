class Solution {
  public:
    vector<string>res;
    void binary_string(string str,int n){
        if(n==0){
            res.push_back(str);
            return ;
        }
        str+='0';
        binary_string(str,n-1);
        str.pop_back();
        str+='1';
        binary_string(str,n-1);
    }
    vector<string> binstr(int n) {
        // code here
        string str="";
        binary_string(str,n);
        return res;
    }
};