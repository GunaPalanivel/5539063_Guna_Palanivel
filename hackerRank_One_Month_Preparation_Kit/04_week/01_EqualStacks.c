int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    int totalFirst = 0;
    int totalSecond = 0; 
    int totalThird = 0;
    
    for(int i = 0; i < h1_count; i++) {
        totalFirst += h1[i];
    }
    
    for(int j = 0; j < h2_count; j++) {
        totalSecond += h2[j];
    }
    
    for(int k = 0; k < h3_count; k++) {
        totalThird += h3[k];
    }
    
    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    
    while(1) {
        if(totalFirst == totalSecond && totalSecond == totalThird) {
            return totalFirst;
        }
        
        if(totalFirst == 0 || totalSecond == 0 || totalThird == 0) {
            return 0;
        }
        
        int maxHeight = totalFirst;
        if(totalSecond > maxHeight) {
            maxHeight = totalSecond;
        }
        if(totalThird > maxHeight) {
            maxHeight = totalThird;
        }
        
        if(totalFirst == maxHeight && pos1 < h1_count) {
            totalFirst -= h1[pos1];
            pos1++;
        }
        else if(totalSecond == maxHeight && pos2 < h2_count) {
            totalSecond -= h2[pos2];
            pos2++;
        }
        else if(totalThird == maxHeight && pos3 < h3_count) {
            totalThird -= h3[pos3];
            pos3++;
        }
        else {
            break;
        }
    }
    
    return 0;
}
