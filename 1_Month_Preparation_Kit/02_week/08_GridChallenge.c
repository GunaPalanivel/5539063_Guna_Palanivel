char* gridChallenge(int grid_count, char** grid) {
    int rows = grid_count;
    int cols = strlen(grid[0]);
    
    for (int r = 0; r < rows; r++) {
        char temp[101];
        strcpy(temp, grid[r]);
        
        for (int i = 0; i < cols - 1; i++) {
            for (int j = i + 1; j < cols; j++) {
                if (temp[i] > temp[j]) {
                    char swap = temp[i];
                    temp[i] = temp[j];
                    temp[j] = swap;
                }
            }
        }
        strcpy(grid[r], temp);
    }
    
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows - 1; r++) {
            if (grid[r][c] > grid[r + 1][c]) {
                static char no[] = "NO";
                return no;
            }
        }
    }
    
    static char yes[] = "YES";
    return yes;
}
