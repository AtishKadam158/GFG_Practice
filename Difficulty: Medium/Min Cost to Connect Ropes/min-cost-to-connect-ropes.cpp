class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        int min_cost=0;

        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(auto itr : arr){
            pq.push(itr);
        }
        
        while(!pq.empty()) {
            if(pq.size()==1) return min_cost;
            int temp1=pq.top();
            pq.pop();
            temp1+=pq.top();
            pq.pop();
            min_cost+=temp1;
            pq.push(temp1);
        }
        
        return min_cost;
    }
};