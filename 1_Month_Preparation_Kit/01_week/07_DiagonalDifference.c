int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int sum1 = 0;
    int sum2 = 0;
    int n = arr_rows;
    
    int idx = 0;
    while (idx < n) {
        sum1 = sum1 + arr[idx][idx];
        sum2 = sum2 + arr[idx][n - idx - 1];
        idx++;
    }
    
    int result = sum1 - sum2;
    if (result < 0) {
        result = result * -1;
    }
    
    return result;
}
