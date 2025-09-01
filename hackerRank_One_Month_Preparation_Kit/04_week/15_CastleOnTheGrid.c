int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    if (startX == goalX && startY == goalY) {
        return 0;
    }
    
    int been_there[100][100];
    int queue_r[10000];
    int queue_c[10000];
    int queue_moves[10000];
    int front_idx = 0;
    int back_idx = 0;
    
    for (int i = 0; i < grid_count; i++) {
        for (int j = 0; j < grid_count; j++) {
            been_there[i][j] = 0;
        }
    }
    
    queue_r[back_idx] = startX;
    queue_c[back_idx] = startY;
    queue_moves[back_idx] = 0;
    back_idx++;
    been_there[startX][startY] = 1;
    
    int dir_r[] = {-1, 1, 0, 0};
    int dir_c[] = {0, 0, -1, 1};
    
    while (front_idx < back_idx) {
        int curr_r = queue_r[front_idx];
        int curr_c = queue_c[front_idx];
        int curr_moves = queue_moves[front_idx];
        front_idx++;
        
        for (int d = 0; d < 4; d++) {
            int new_r = curr_r + dir_r[d];
            int new_c = curr_c + dir_c[d];
            
            while (new_r >= 0 && new_r < grid_count && 
                   new_c >= 0 && new_c < grid_count && 
                   grid[new_r][new_c] == '.') {
                
                if (!been_there[new_r][new_c]) {
                    been_there[new_r][new_c] = 1;
                    
                    if (new_r == goalX && new_c == goalY) {
                        return curr_moves + 1;
                    }
                    
                    queue_r[back_idx] = new_r;
                    queue_c[back_idx] = new_c;
                    queue_moves[back_idx] = curr_moves + 1;
                    back_idx++;
                }
                
                new_r += dir_r[d];
                new_c += dir_c[d];
            }
        }
    }
    
    return -1;
}
