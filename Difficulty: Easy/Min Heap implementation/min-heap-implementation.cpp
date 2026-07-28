class minHeap {
  private:
    // Initialize your data members
    vector<int>heap;

  public:
    
    void push(int x) {
        // Insert x into the heap
        int n=heap.size();
        heap.push_back(x);
        while(n){
            int parent=(n-1)/2;
            if(heap[parent] > heap [n]){
                swap(heap[parent], heap [n]);
                n=parent;
            }else
                break;
        }
        
    }
    void heapify(int i){
        int n=heap.size();
        int x=i;
        int l=2*i+1;
        int r=2*i+2;
        
        if(l<n && heap[l]<heap[x])
            x=l;
        if(r<n && heap[r]<heap[x])
            x=r;
        if(x!=i){
            swap(heap[x],heap[i]);
            heapify(x);
        }
    }
    void pop() {
        // Remove the top (minimum) element
        int n=heap.size();
        if(n==0)
            return ;
        heap[0]=heap[n-1];
        heap.pop_back();
        heapify(0);
    }

    int peek() {
        // Return the top element or -1 if empty
        if(heap.size()==0)
            return -1;
        return heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};