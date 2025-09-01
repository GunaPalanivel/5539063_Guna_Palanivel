#define MAX_N 100001
int parent[MAX_N];
int visited[MAX_N];

int find_parent(int x) {
    if(parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}

void union_sets(int a, int b) {
    int pa = find_parent(a);
    int pb = find_parent(b);
    if(pa != pb) {
        parent[pa] = pb;
    }
}

long long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int** cities) {
    if(c_lib <= c_road) {
        return (long long)n * c_lib;
    }
    
    // Initialize parent array
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        visited[i] = 0;
    }
    
    // Union connected cities
    for(int i = 0; i < cities_rows; i++) {
        union_sets(cities[i][0], cities[i][1]);
    }
    
    // Count connected components
    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(find_parent(i) == i) {
            components++;
        }
    }
    
    int roads_needed = n - components;
    return (long long)components * c_lib + (long long)roads_needed * c_road;
}