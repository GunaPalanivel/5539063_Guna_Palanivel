char* timeConversion(char* s) {
    static char result[20];
    int hh, mm, ss;
    char tag[3];
    sscanf(s, "%d:%d:%d%2s", &hh, &mm, &ss, tag);

    if (strcmp(tag, "AM") == 0) {
        if (hh == 12) hh = 0;
    } else {
        if (hh != 12) hh += 12;
    }

    sprintf(result, "%02d:%02d:%02d", hh, mm, ss);
    return result;
}
