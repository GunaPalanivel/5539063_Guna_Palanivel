void minimumBribes(int q_count, int* q) {
    int moves = 0;
    for (int i = 0; i < q_count; i++) {
        int shift = q[i] - (i + 1);
        if (shift > 2) {
            printf("Too chaotic\n");
            return;
        }
    }
    for (int i = 0; i < q_count; i++) {
        int start = q[i] - 2;
        if (start < 0) start = 0;
        for (int j = start; j < i; j++) {
            if (q[j] > q[i]) moves++;
        }
    }
    printf("%d\n", moves);
}
