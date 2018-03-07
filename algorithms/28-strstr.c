// 4ms 44.86%

int strStr(char* haystack, char* needle) {
    if (!haystack || !needle)   return -1;
    int h_len = strlen(haystack), n_len = strlen(needle);
    if (n_len > h_len) return -1;
    if (n_len == h_len) return strcmp(haystack, needle) == 0 ? 0 : -1;

    int n_idx = 0, ncand, nrem, ncand_new = 0;
    int *candidates = (int *)malloc(h_len * sizeof(int));
    for (int i = 0; i < h_len; ++i)
        candidates[i] = i-1;
    ncand = h_len;
    nrem = n_len;
    for (; n_idx < n_len; ++n_idx) {
        --nrem;
        ncand_new = 0;
        for (int ci = 0; ci < ncand && candidates[ci] < h_len - nrem; ++ci) {
            int next = candidates[ci] + 1;
            char hay = haystack[next];
            if (hay == needle[n_idx]) {
                candidates[ncand_new++] = next;
            }
        }
        if (ncand_new == 0) return -1;
        ncand = ncand_new;
    }
    int answer = candiates[0] - n_len + 1;
    free(candidates);
    return answer;
}
