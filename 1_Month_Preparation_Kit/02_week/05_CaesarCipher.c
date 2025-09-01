char* caesarCipher(char* s, int k) {
    int textLength = strlen(s);
    char* encodedString = malloc((textLength + 1) * sizeof(char));
    
    int shiftAmount = k % 26;
    
    for(int pos = 0; pos < textLength; pos++) {
        char currentChar = s[pos];
        
        if(currentChar >= 'a' && currentChar <= 'z') {
            int charPosition = currentChar - 'a';
            charPosition = charPosition + shiftAmount;
            if(charPosition >= 26) {
                charPosition = charPosition - 26;
            }
            encodedString[pos] = 'a' + charPosition;
        }
        else if(currentChar >= 'A' && currentChar <= 'Z') {
            int charPosition = currentChar - 'A';  
            charPosition = charPosition + shiftAmount;
            if(charPosition >= 26) {
                charPosition = charPosition - 26;
            }
            encodedString[pos] = 'A' + charPosition;
        }
        else {
            encodedString[pos] = currentChar;
        }
    }
    
    encodedString[textLength] = '\0';
    return encodedString;
}
