int lilysHomework(int arr_count, int* arr) {
    int* work_array = malloc(arr_count * sizeof(int));
    int* asc_sorted = malloc(arr_count * sizeof(int));
    int* desc_sorted = malloc(arr_count * sizeof(int));
    
    for(int i = 0; i < arr_count; i++) {
        work_array[i] = arr[i];
        asc_sorted[i] = arr[i];
    }
    
    for(int i = 0; i < arr_count - 1; i++) {
        for(int j = i + 1; j < arr_count; j++) {
            if(asc_sorted[i] > asc_sorted[j]) {
                int temp = asc_sorted[i];
                asc_sorted[i] = asc_sorted[j];
                asc_sorted[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < arr_count; i++) {
        desc_sorted[i] = asc_sorted[arr_count - 1 - i];
    }
    
    int count_asc_swaps(int* original, int* target) {
        int* visited = malloc(arr_count * sizeof(int));
        int* pos_in_target = malloc(arr_count * sizeof(int));
        int total_swaps = 0;
        
        for(int i = 0; i < arr_count; i++) {
            visited[i] = 0;
            pos_in_target[i] = -1;
            
            for(int j = 0; j < arr_count; j++) {
                if(target[j] == original[i]) {
                    pos_in_target[i] = j;
                    break;
                }
            }
        }
        
        for(int i = 0; i < arr_count; i++) {
            if(visited[i] || pos_in_target[i] == i) {
                continue;
            }
            
            int cycle_count = 0;
            int curr_pos = i;
            
            while(!visited[curr_pos]) {
                visited[curr_pos] = 1;
                curr_pos = pos_in_target[curr_pos];
                cycle_count++;
            }
            
            if(cycle_count > 1) {
                total_swaps += (cycle_count - 1);
            }
        }
        
        free(visited);
        free(pos_in_target);
        return total_swaps;
    }
    
    int swaps_for_asc = count_asc_swaps(arr, asc_sorted);
    int swaps_for_desc = count_asc_swaps(arr, desc_sorted);
    
    free(work_array);
    free(asc_sorted);
    free(desc_sorted);
    
    return (swaps_for_asc < swaps_for_desc) ? swaps_for_asc : swaps_for_desc;
}
