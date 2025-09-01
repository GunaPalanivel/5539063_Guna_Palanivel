int sockMerchant(int n, int ar_count, int* ar) {
    int pairs = 0;
    int sockTypes[101];
    
    for(int idx = 0; idx <= 100; idx++) {
        sockTypes[idx] = 0;
    }
    
    for(int idx = 0; idx < n; idx++) {
        sockTypes[ar[idx]]++;
    }
    
    for(int idx = 0; idx <= 100; idx++) {
        pairs = pairs + sockTypes[idx] / 2;
    }
    
    return pairs;
}
