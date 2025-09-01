void maxSubarray(int arr_count, int* arr, int* result) {

    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for(int i = 1; i < arr_count; i++) {
        maxEndingHere = (arr[i] > maxEndingHere + arr[i]) ? arr[i] : maxEndingHere + arr[i];
        maxSoFar = (maxSoFar > maxEndingHere) ? maxSoFar : maxEndingHere;
    }
    
    int maxSubsequence = 0;
    int hasPositive = 0;
    int maxElement = INT_MIN;
    
    for(int i = 0; i < arr_count; i++) {
        if(arr[i] > 0) {
            maxSubsequence += arr[i];
            hasPositive = 1;
        }
        if(arr[i] > maxElement) maxElement = arr[i];
    }
    
    if(!hasPositive) maxSubsequence = maxElement;
    
    result[0] = maxSoFar;
    result[1] = maxSubsequence;
}
