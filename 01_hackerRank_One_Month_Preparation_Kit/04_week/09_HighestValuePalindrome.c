#define MAX_N 100
int visited[MAX_N][MAX_N];
int queue_x[MAX_N*MAX_N], queue_y[MAX_N*MAX_N], queue_dist[MAX_N*MAX_N];
int front = 0, rear = 0;

int minimumMoves(int n, char** grid, int startX, int startY, int goalX, int goalY) {
    memset(visited, 0, sizeof(visited));
    front = rear = 0;
    
    queue_x[rear] = startX;
    queue_y[rear] = startY;
    queue_dist[rear] = 0;
    rear++;
    visited[startX][startY] = 1;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while(front < rear) {
        int x = queue_x[front];
        int y = queue_y[front];
        int dist = queue_dist[front];
        front++;
        
        if(x == goalX && y == goalY) {
            return dist;
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            while(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.') {
                if(!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    queue_x[rear] = nx;
                    queue_y[rear] = ny;
                    queue_dist[rear] = dist + 1;
                    rear++;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }
    return -1;
}