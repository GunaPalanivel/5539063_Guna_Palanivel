int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findZigZagSequence(int numbers[], int n) {
    qsort(numbers, n, sizeof(int), compare);
    
    int mid = n / 2;
    int temp = numbers[mid];
    numbers[mid] = numbers[n-1];
    numbers[n-1] = temp;
    
    int start = mid + 1;
    int end = n - 2;
    
    while(start < end) {
        temp = numbers[start];
        numbers[start] = numbers[end];
        numbers[end] = temp;
        start++;
        end--;
    }
    
    for(int i = 0; i < n; i++) {
        if(i > 0) printf(" ");
        printf("%d", numbers[i]);
    }
    printf("\n");
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    
    while(test_cases--) {
        int n;
        scanf("%d", &n);
        int numbers[n];
        
        for(int i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }
        
        findZigZagSequence(numbers, n);
    }
    
    return 0;
}
