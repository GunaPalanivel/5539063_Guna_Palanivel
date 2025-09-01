char** bomberMan(int n, int rows, char** grid, int* result_count) {
    *result_count = rows;
    int cols = strlen(grid[0]);
    if (n == 1) return grid;
    if (n % 2 == 0) {
        char** full = malloc(rows * sizeof(char*));
        for (int i = 0; i < rows; i++) {
            full[i] = malloc(cols + 1);
            for (int j = 0; j < cols; j++) full[i][j] = 'O';
            full[i][cols] = '\0';
        }
        return full;
    }
    int phase = ((n - 3) % 4) + 1;
    char** state = malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        state[i] = malloc(cols + 1);
        strcpy(state[i], grid[i]);
    }
    for (int step = 1; step <= 2; step++) {
        char** temp = malloc(rows * sizeof(char*));
        for (int i = 0; i < rows; i++) {
            temp[i] = malloc(cols + 1);
            for (int j = 0; j < cols; j++) temp[i][j] = 'O';
            temp[i][cols] = '\0';
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (state[i][j] == 'O') {
                    temp[i][j] = '.';
                    if (i > 0) temp[i - 1][j] = '.';
                    if (i < rows - 1) temp[i + 1][j] = '.';
                    if (j > 0) temp[i][j - 1] = '.';
                    if (j < cols - 1) temp[i][j + 1] = '.';
                }
            }
        }
        state = temp;
        if (step == phase) return state;
    }
    return state;
}
