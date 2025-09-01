#define SIZE 100000

int inStack[SIZE], outStack[SIZE];
int inTop = -1, outTop = -1;

void pushIn(int val) {
    inStack[++inTop] = val;
}

int popOut() {
    if (outTop == -1) {
        while (inTop >= 0) {
            outStack[++outTop] = inStack[inTop--];
        }
    }
    return outStack[outTop--];
}

int peekFront() {
    if (outTop == -1) {
        while (inTop >= 0) {
            outStack[++outTop] = inStack[inTop--];
        }
    }
    return outStack[outTop];
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int type, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            pushIn(x);
        } else if (type == 2) {
            popOut();
        } else {
            printf("%d\n", peekFront());
        }
    }
    return 0;
}
