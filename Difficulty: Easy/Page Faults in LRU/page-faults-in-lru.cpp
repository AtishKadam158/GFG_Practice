class Solution {
  public:
    int pageFaults(vector<int>& pages, int c) {
        // code here
        unordered_map<int, list<int>::iterator> mp;
        int n=pages.size();
        int ct=0;
        list<int> l;
        for(int i=0;i<n;i++){
            if(mp.find(pages[i]) != mp.end()){
                l.erase(mp[pages[i]]);
                l.push_front(pages[i]);
                mp[pages[i]] = l.begin();
                
            }else{
                ct++;
                if (l.size() == c) {
                    int lru = l.back();
                    l.pop_back();
                    mp.erase(lru);
                }
                l.push_front(pages[i]);
                mp[pages[i]] = l.begin();
            }
            
        }
        return ct;
    }
};