class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        for(auto itr: arr) 
            pq.push(itr);
        for(int i=0;i<k-1;i++)
            pq.pop();
        return pq.top();
    }
};