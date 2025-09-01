char* isBalanced(char* s) {
    int n = strlen(s);
    char *stack = malloc(n);
    int top = -1;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                free(stack);
                static char no[] = "NO";
                return no;
            }
            char t = stack[top--];
            if ((c == ')' && t != '(') ||
                (c == ']' && t != '[') ||
                (c == '}' && t != '{')) {
                free(stack);
                static char no[] = "NO";
                return no;
            }
        }
    }
    free(stack);
    if (top == -1) {
        static char yes[] = "YES";
        return yes;
    } else {
        static char no[] = "NO";
        return no;
    }
}
