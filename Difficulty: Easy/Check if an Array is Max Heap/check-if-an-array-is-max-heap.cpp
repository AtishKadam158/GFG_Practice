class Solution {
  public:
    bool isMaxHeap(vector<int> &heap) {
        // code here
        int n=heap.size();
        for(int i=0;i<n/2;i++){
            int l=2*i+1;
            int r=2*i+2;
            if((l<n && heap[i] < heap[l]) ||(r<n && heap[i] < heap[r]))
                return false;
        }
        return true;
    }
};
