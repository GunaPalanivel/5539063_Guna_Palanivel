int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int* tmp = malloc(ranked_count * sizeof(int));
    int uniq = 0;
    tmp[uniq++] = ranked[0];
    for (int i = 1; i < ranked_count; i++) {
        if (ranked[i] != tmp[uniq - 1]) {
            tmp[uniq++] = ranked[i];
        }
    }
    int* out = malloc(player_count * sizeof(int));
    int pos = uniq - 1;
    for (int j = 0; j < player_count; j++) {
        while (pos >= 0 && player[j] >= tmp[pos]) {
            pos--;
        }
        out[j] = pos + 2;
    }
    *result_count = player_count;
    return out;
}
