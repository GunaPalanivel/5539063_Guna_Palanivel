int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return num1 - num2;
}

int maxMin(int k, int arr_count, int* arr) {
    qsort(arr, arr_count, sizeof(int), compare);
    
    int smallestGap = arr[k-1] - arr[0];
    
    int i = 1;
    while(i <= arr_count - k) {
        int gap = arr[i + k - 1] - arr[i];
        if(gap < smallestGap) {
            smallestGap = gap;
        }
        i++;
    }
    
    return smallestGap;
}
