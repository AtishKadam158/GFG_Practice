class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>, greater<int>>pq;
        int n=arr.size();
        for(int i=0;i<k;i++) 
            pq.push(arr[i]);
        for(int i=k;i<n;i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        } 
        
        return pq.top();
    }
};