char* isValid(char* s) {
    int freq[26];
    for (int i = 0; i < 26; i++) freq[i] = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    int count[26], k = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) count[k++] = freq[i];
    }
    int a = 0, b = 0, ca = 0, cb = 0;
    for (int i = 0; i < k; i++) {
        if (a == 0) {
            a = count[i];
            ca++;
        } else if (count[i] == a) {
            ca++;
        } else if (b == 0) {
            b = count[i];
            cb++;
        } else if (count[i] == b) {
            cb++;
        } else {
            static char no[] = "NO";
            return no;
        }
    }
    if (b == 0) {
        static char yes[] = "YES";
        return yes;
    }
    if (ca == 1 && (a - 1 == b || a - 1 == 0)) {
        static char yes[] = "YES";
        return yes;
    }
    if (cb == 1 && (b - 1 == a || b - 1 == 0)) {
        static char yes[] = "YES";
        return yes;
    }
    static char no[] = "NO";
    return no;
}
