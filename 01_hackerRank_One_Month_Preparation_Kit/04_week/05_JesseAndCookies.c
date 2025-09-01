int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int hackerlandRadioTransmitters(int x_count, int* x, int k) {
    qsort(x, x_count, sizeof(int), compare);
    
    int transmitters = 0;
    int i = 0;
    
    while(i < x_count) {
        transmitters++;
        int start = x[i];
        
        while(i < x_count && x[i] <= start + k) {
            i++;
        }
        
        int transmitter_pos = x[i-1];
        
        while(i < x_count && x[i] <= transmitter_pos + k) {
            i++;
        }
    }
    
    return transmitters;
}