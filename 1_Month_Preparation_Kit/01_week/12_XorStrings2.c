int main() {
    char first[10005], second[10005];
    if (scanf("%s", first) != 1) return 0;
    if (scanf("%s", second) != 1) return 0;
    int n = strlen(first);
    for (int i = 0; i < n; i++) {
        if (first[i] == second[i]) {
            putchar('0');
        } else {
            putchar('1');
        }
    }
    putchar('\n');
    return 0;
}
