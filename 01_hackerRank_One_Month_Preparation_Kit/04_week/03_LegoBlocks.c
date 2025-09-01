#define MAX_SIZE 100000

int heap[MAX_SIZE];
int heap_size = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(int idx) {
    if (idx && heap[(idx-1)/2] > heap[idx]) {
        swap(&heap[idx], &heap[(idx-1)/2]);
        heapify_up((idx-1)/2);
    }
}

void heapify_down(int idx) {
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;
    
    if (left < heap_size && heap[left] < heap[smallest])
        smallest = left;
    if (right < heap_size && heap[right] < heap[smallest])
        smallest = right;
    
    if (smallest != idx) {
        swap(&heap[idx], &heap[smallest]);
        heapify_down(smallest);
    }
}

void insert(int val) {
    heap[heap_size] = val;
    heapify_up(heap_size);
    heap_size++;
}

void delete_val(int val) {
    int idx = -1;
    for(int i = 0; i < heap_size; i++) {
        if(heap[i] == val) {
            idx = i;
            break;
        }
    }
    
    if(idx != -1) {
        heap[idx] = heap[heap_size-1];
        heap_size--;
        heapify_down(idx);
    }
}

int get_min() {
    return heap[0];
}

int main() {
    int q;
    scanf("%d", &q);
    
    while(q--) {
        int type;
        scanf("%d", &type);
        
        if(type == 1) {
            int v;
            scanf("%d", &v);
            insert(v);
        }
        else if(type == 2) {
            int v;
            scanf("%d", &v);
            delete_val(v);
        }
        else {
            printf("%d\n", get_min());
        }
    }
    return 0;
}