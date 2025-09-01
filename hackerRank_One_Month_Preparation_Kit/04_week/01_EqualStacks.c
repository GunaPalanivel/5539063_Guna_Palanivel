int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    int h1Height = 0, h2Height = 0, h3Height = 0;
    int h1Index = 0, h2Index = 0, h3Index = 0;
    
    for(int i = 0; i < h1_count; i++) h1Height += h1[i];
    for(int i = 0; i < h2_count; i++) h2Height += h2[i];
    for(int i = 0; i < h3_count; i++) h3Height += h3[i];
    
    while(h1Height != h2Height || h2Height != h3Height) {
        if(h1Height == 0 || h2Height == 0 || h3Height == 0) return 0;
        
        if(h1Height >= h2Height && h1Height >= h3Height) {
            h1Height -= h1[h1Index++];
        }
        else if(h2Height >= h1Height && h2Height >= h3Height) {
            h2Height -= h2[h2Index++];
        }
        else {
            h3Height -= h3[h3Index++];
        }
    }
    return h1Height;
}
