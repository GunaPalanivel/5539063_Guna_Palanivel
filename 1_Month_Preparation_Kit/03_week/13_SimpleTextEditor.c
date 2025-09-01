#define MAXLEN 1000000

char *stack[100000];
int top = -1;

int main() {
    int q;
    scanf("%d", &q);
    char *text = calloc(MAXLEN, sizeof(char));
    text[0] = '\0';

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            char buf[MAXLEN];
            scanf("%s", buf);
            stack[++top] = strdup(text);
            strcat(text, buf);
        } else if (t == 2) {
            int k;
            scanf("%d", &k);
            stack[++top] = strdup(text);
            int len = strlen(text);
            text[len - k] = '\0';
        } else if (t == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", text[k - 1]);
        } else if (t == 4) {
            if (top >= 0) {
                free(text);
                text = stack[top--];
            }
        }
    }
    free(text);
    return 0;
}
