char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
    int swap_val;
    
    for(int round = 0; round < A_count - 1; round++) {
        for(int pos = 0; pos < A_count - round - 1; pos++) {
            if(A[pos] > A[pos + 1]) {
                swap_val = A[pos];
                A[pos] = A[pos + 1];
                A[pos + 1] = swap_val;
            }
        }
    }
    
    for(int round = 0; round < B_count - 1; round++) {
        for(int pos = 0; pos < B_count - round - 1; pos++) {
            if(B[pos] < B[pos + 1]) {
                swap_val = B[pos];
                B[pos] = B[pos + 1];
                B[pos + 1] = swap_val;
            }
        }
    }
    
    int check_idx = 0;
    while(check_idx < A_count) {
        if(A[check_idx] + B[check_idx] < k) {
            static char result_no[] = "NO";
            return result_no;
        }
        check_idx++;
    }
    
    static char result_yes[] = "YES";
    return result_yes;
}
