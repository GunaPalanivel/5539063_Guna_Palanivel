int* waiter(int number_count, int* number, int q, int* result_count) {
    int primes[q], countp = 0, val = 2;
    while (countp < q) {
        int prime = 1;
        for (int j = 2; j * j <= val; j++) {
            if (val % j == 0) { prime = 0; break; }
        }
        if (prime) primes[countp++] = val;
        val++;
    }

    int *stackA = malloc(number_count * sizeof(int));
    int topA = number_count - 1;
    for (int i = 0; i < number_count; i++) stackA[i] = number[i];

    int cap = number_count * (q + 1);
    int *ans = malloc(cap * sizeof(int));
    int out = 0;

    for (int i = 0; i < q; i++) {
        int *nextA = malloc(number_count * sizeof(int));
        int topNextA = -1;
        int *stackB = malloc(number_count * sizeof(int));
        int topB = -1;

        while (topA >= 0) {
            int v = stackA[topA--];
            if (v % primes[i] == 0) {
                stackB[++topB] = v;
            } else {
                nextA[++topNextA] = v;
            }
        }

        while (topB >= 0) {
            ans[out++] = stackB[topB--];
        }

        free(stackA);
        free(stackB);
        stackA = nextA;
        topA = topNextA;
    }

    while (topA >= 0) {
        ans[out++] = stackA[topA--];
    }
    free(stackA);

    *result_count = out;
    return ans;
}
