long flippingBits(long n) {
    long thirty_two_ones = 4294967295L;
    long answer = n ^ thirty_two_ones;
    return answer;
}
