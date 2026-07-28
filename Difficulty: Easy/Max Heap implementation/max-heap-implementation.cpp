class maxHeap {
  private:
    // Initialize your data members
    vector<int>heap;

  public:

    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        int n=heap.size()-1;
        while(n){
            int parent = (n-1)/2;
            if(heap[parent] < heap[n]){
                swap(heap[parent],heap[n]);
                n=parent;
            }else
                break;
        }
        
    }
    void heapify(){
        int ind=0;
        int n=heap.size();
        while(true){
            int x=ind;
            int l=2*ind+1;
            int r=2*ind+2;
            
            if(l<n && heap[x] < heap[l])
                x=l;
            if(r<n && heap[x] < heap[r])
                x=r;
                
            if(x==ind) break;
            swap(heap[x],heap[ind]);
            ind=x;
        }
    }
    void pop() {
        // Remove the top (maximum) element
        int n=heap.size();
        if(!heap.empty()){
            swap(heap[0],heap[n-1]);
            heap.pop_back();
            heapify();
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        if(!heap.empty())
            return heap[0];
        return -1;
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};