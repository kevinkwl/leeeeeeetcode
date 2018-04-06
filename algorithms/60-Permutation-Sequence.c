char* getPermutation(int n, int k) {
    int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    char* perm = (char*)malloc(sizeof(char) * (n+1));
    bool used[9] = {false, false};
    perm[n] = '\0';
    int d = 0, hd = 0;
    char tmp;
    while (n > 0 && k > 0) {
        hd = (k-1) / fact[n-1];
        int i, j = 0;
        for (i = 0; i < 9; i++)
            if (!used[i] && j++ == hd) {
                used[i] = true;
                perm[d] = '0' + i + 1;
                break;
            }
        k -= hd * fact[n-1];
        n--;
        d++;
    }
    return perm;
}
