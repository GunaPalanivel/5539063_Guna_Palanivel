char* balancedSums(int arr_count, int* arr) {
    int whole_sum = 0;
    int j;
    
    for(j = 0; j < arr_count; j++) {
        whole_sum = whole_sum + arr[j];
    }
    
    int sum_left = 0;
    int sum_right;
    
    for(j = 0; j < arr_count; j++) {
        sum_right = whole_sum - sum_left - arr[j];
        
        if(sum_left == sum_right) {
            static char answer1[] = "YES";
            return answer1;
        }
        
        sum_left = sum_left + arr[j];
    }
    
    static char answer2[] = "NO";
    return answer2;
}
