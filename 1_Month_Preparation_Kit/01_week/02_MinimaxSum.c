void miniMaxSum(int arr_count, int* arr) {
    long long total = 0; 
    int smallest = arr[0];
    int biggest = arr[0];

    for(int i = 0; i < arr_count; i++) {
        total += arr[i];
        if(arr[i] < smallest) smallest = arr[i];
        if(arr[i] > biggest) biggest = arr[i];
    }
    
    long long minSum = total - biggest;
    long long maxSum = total - smallest;

    printf("%lld %lld\n", minSum, maxSum);
}
