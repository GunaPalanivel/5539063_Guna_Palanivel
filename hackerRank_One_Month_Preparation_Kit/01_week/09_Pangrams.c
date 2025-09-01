char* pangrams(char* s) {
    int letterFound[26];
    int i;
    
    for(i = 0; i < 26; i++) {
        letterFound[i] = 0;
    }
    
    int stringLength = strlen(s);
    for(i = 0; i < stringLength; i++) {
        char currentChar = s[i];
        
        if(currentChar >= 'a' && currentChar <= 'z') {
            letterFound[currentChar - 'a'] = 1;
        }
        else if(currentChar >= 'A' && currentChar <= 'Z') {
            letterFound[currentChar - 'A'] = 1;
        }
    }
    
    int totalLettersFound = 0;
    for(i = 0; i < 26; i++) {
        if(letterFound[i] == 1) {
            totalLettersFound++;
        }
    }
    
    if(totalLettersFound == 26) {
        char* result = malloc(8 * sizeof(char));
        strcpy(result, "pangram");
        return result;
    } else {
        char* result = malloc(12 * sizeof(char));
        strcpy(result, "not pangram");
        return result;
    }
}
