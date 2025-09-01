char* counterGame(long n) {
    static char a[] = "Louise";
    static char b[] = "Richard";
    int steps = 0;
    while (n > 1) {
        if ((n & (n - 1)) == 0) {
            n >>= 1;
        } else {
            long p = 1L << ((long)log2((double)n));
            n -= p;
        }
        steps ^= 1;
    }
    if (steps) return a;
    return b;
}
