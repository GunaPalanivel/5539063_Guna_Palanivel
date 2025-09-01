int lonelyinteger(int a_count, int* a) {
    int unique_num = 0;
    int index = 0;
    
    while (index < a_count) {
        unique_num ^= a[index];
        index++;
    }
    
    return unique_num;
}
