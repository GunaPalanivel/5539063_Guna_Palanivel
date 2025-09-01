int heap[1000000];
int heap_size = 0;

void heapify_up(int idx) {
    while(idx > 0 && heap[(idx-1)/2] > heap[idx]) {
        int temp = heap[idx];
        heap[idx] = heap[(idx-1)/2];
        heap[(idx-1)/2] = temp;
        idx = (idx-1)/2;
    }
}

void heapify_down(int idx) {
    while(1) {
        int smallest = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        
        if(left < heap_size && heap[left] < heap[smallest])
            smallest = left;
        if(right < heap_size && heap[right] < heap[smallest])
            smallest = right;
            
        if(smallest == idx) break;
        
        int temp = heap[idx];
        heap[idx] = heap[smallest];
        heap[smallest] = temp;
        idx = smallest;
    }
}

void insert(int val) {
    heap[heap_size] = val;
    heapify_up(heap_size);
    heap_size++;
}

int extract_min() {
    int min_val = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
    heapify_down(0);
    return min_val;
}

int cookies(int k, int A_count, int* A) {
    heap_size = 0;
    
    for(int i = 0; i < A_count; i++) {
        insert(A[i]);
    }
    
    int operations = 0;
    
    while(heap_size > 1 && heap[0] < k) {
        int first = extract_min();
        int second = extract_min();
        int combined = first + 2 * second;
        insert(combined);
        operations++;
    }
    
    return (heap_size > 0 && heap[0] >= k) ? operations : -1;
}