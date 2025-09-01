int birthday(int s_count, int* s, int d, int m) {
    int ways = 0;
    int i, j;
    
    for (i = 0; i <= s_count - m; i++) {
        int segment_sum = 0;
        for (j = i; j < i + m; j++) {
            segment_sum += s[j];
        }
        if (segment_sum == d) {
            ways++;
        }
    }
    
    return ways;
}
