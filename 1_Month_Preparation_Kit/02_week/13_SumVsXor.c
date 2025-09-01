long sumXor(long n) {
    if(n==0) return 1;
    long zeros=0;
    while(n>0){
        if((n & 1L)==0){
            zeros++;
        }
        n >>= 1;
    }
    long res=1;
    while(zeros>0){
        res <<= 1;
        zeros--;
    }
    return res;
}
