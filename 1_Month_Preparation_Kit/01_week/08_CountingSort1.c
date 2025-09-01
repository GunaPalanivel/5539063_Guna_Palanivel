int* countingSort(int arr_count, int* arr, int* result_count) {
    int* freq = malloc(100 * sizeof(int));
    
    int idx = 0;
    while(idx < 100) {
        freq[idx] = 0;
        idx++;
    }
    
    int pos = 0;
    while(pos < arr_count) {
        int val = arr[pos];
        freq[val] = freq[val] + 1;
        pos++;
    }
    
    *result_count = 100;
    return freq;
}
