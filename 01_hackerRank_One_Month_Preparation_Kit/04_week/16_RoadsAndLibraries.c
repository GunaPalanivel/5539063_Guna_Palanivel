long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int cities_columns, int** cities) {
    if (c_lib <= c_road) {
        return (long)n * c_lib;
    }
    
    int parent[100001];
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    int find_root(int x) {
        if (parent[x] != x) {
            parent[x] = find_root(parent[x]);
        }
        return parent[x];
    }
    
    void merge_groups(int a, int b) {
        int root_a = find_root(a);
        int root_b = find_root(b);
        if (root_a != root_b) {
            parent[root_a] = root_b;
        }
    }
    
    for (int i = 0; i < cities_rows; i++) {
        merge_groups(cities[i][0], cities[i][1]);
    }
    
    int unique_groups = 0;
    for (int i = 1; i <= n; i++) {
        if (find_root(i) == i) {
            unique_groups++;
        }
    }
    
    int roads_to_build = n - unique_groups;
    return (long)unique_groups * c_lib + (long)roads_to_build * c_road;
}
