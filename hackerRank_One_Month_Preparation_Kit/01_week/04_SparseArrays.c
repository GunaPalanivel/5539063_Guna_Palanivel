int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    *result_count = queries_count;
    int *outcomes = malloc(queries_count * sizeof(int));
    if (!outcomes) exit(1);

    for (int qi = 0; qi < queries_count; qi++) {
        int tally = 0;
        char *qword = queries[qi];
        for (int si = 0; si < strings_count; si++) {
            if (strcmp(strings[si], qword) == 0) {
                tally++;
            }
        }
        outcomes[qi] = tally;
    }
    return outcomes;
}
