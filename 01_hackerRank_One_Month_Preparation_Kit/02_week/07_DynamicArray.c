int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** lists = malloc(n * sizeof(int*));
    int* sizes = malloc(n * sizeof(int));
    int* capacities = malloc(n * sizeof(int));
    
    for(int j = 0; j < n; j++) {
        lists[j] = malloc(16 * sizeof(int));
        sizes[j] = 0;
        capacities[j] = 16;
    }
    
    int lastAnswer = 0;
    int* answers = malloc(queries_rows * sizeof(int));
    *result_count = 0;
    
    for(int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1]; 
        int y = queries[i][2];
        
        int seq = (x ^ lastAnswer) % n;
        
        if(type == 1) {
            if(sizes[seq] >= capacities[seq]) {
                capacities[seq] *= 2;
                lists[seq] = realloc(lists[seq], capacities[seq] * sizeof(int));
            }
            lists[seq][sizes[seq]] = y;
            sizes[seq]++;
        }
        else if(type == 2) {
            int index = y % sizes[seq];
            lastAnswer = lists[seq][index];
            answers[*result_count] = lastAnswer;
            (*result_count)++;
        }
    }
    
    for(int k = 0; k < n; k++) {
        free(lists[k]);
    }
    free(lists);
    free(sizes);
    free(capacities);
    
    return answers;
}
