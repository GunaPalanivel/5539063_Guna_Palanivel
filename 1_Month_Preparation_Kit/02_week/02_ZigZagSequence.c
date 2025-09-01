int main() {
    int testCount;
    scanf("%d", &testCount);
    
    while(testCount--) {
        int arraySize;
        scanf("%d", &arraySize);
        
        int numbers[arraySize];
        for(int i = 0; i < arraySize; i++) {
            scanf("%d", &numbers[i]);
        }
        
        findZigZagSequence(numbers, arraySize);
    }
    
    return 0;
}