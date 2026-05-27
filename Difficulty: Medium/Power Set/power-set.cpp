class Solution {
  public:
    vector<string>powerset;
    
    void power_set(string &s,string &str,int i,int n){
        if(i==n){
            powerset.push_back(str);
            return ;
        }
        str+=s[i];
        power_set(s,str,i+1,n);
        str.pop_back();
        power_set(s,str,i+1,n);
    }
    
    vector<string> AllPossibleStrings(string s) {
        // Code here
        int n=s.size();
        string str="";
        power_set(s,str,0,n);
        sort(powerset.begin(),powerset.end());
        return powerset;
    }
};