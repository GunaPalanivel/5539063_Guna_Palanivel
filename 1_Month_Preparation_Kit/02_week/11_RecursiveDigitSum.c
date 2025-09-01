int superDigit(char* n, int k) {
    long long digitSum = 0;
    int i = 0;
    
    while(n[i] != '\0') {
        digitSum = digitSum + (n[i] - '0');
        i++;
    }
    
    digitSum = (digitSum * k) % 9;
    
    if(digitSum == 0) {
        return 9;
    }
    
    return (int)digitSum;
}
#include <stdio.h>