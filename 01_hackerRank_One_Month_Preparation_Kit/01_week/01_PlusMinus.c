void plusMinus(int arr_count, int* arr) {
    int positives = 0, negatives = 0, zeros = 0;

    for (int i = 0; i < arr_count; i++) {
        if (arr[i] > 0) {
            positives++;
        } else if (arr[i] < 0) {
            negatives++;
        } else {
            zeros++;
        }
    }
    double total = (double)arr_count;

    printf("%.6f\n", positives / total);
    printf("%.6f\n", negatives / total);
    printf("%.6f\n", zeros / total);
}
