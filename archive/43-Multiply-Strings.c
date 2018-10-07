char* multiply(char* num1, char* num2) {
    int d1 = strlen(num1), d2 = strlen(num2);
    int ans_len = d1 + d2;
    int *ans = (int *)malloc(ans_len * sizeof(int));
    memset(ans, 0, sizeof(int) * ans_len);
    int cur = ans_len - 1;
    
    if (d1 != 0 && d2 != 0) {
        int res = 0, m, i = 0;
        for (int i = 0; i < d2; i++) {
            cur = ans_len - i;
            m = num2[d2-1-i] - '0';
            if (m == 0)
                continue;
            for (int d = d1 - 1; d >= 0; d--) {
                cur--;
                res = (num1[d] - '0') * m + ans[cur];
                ans[cur] = res % 10;
                ans[cur-1] += res / 10;
            }
            while (cur > 0 && ans[cur-1] >= 10) {
                cur--;
                res = ans[cur];
                ans[cur] = res % 10;
                if (cur > 1)
                    ans[cur-1] = res / 10;
            }
        }
    }
    cur = 0;
    while (cur < ans_len - 1 && ans[cur] == 0)
        cur++;
    char *chans = (char *)malloc((ans_len-cur+1) * sizeof(char));
    int i = 0;
    for (; cur < ans_len; i++, cur++)
        chans[i] = '0' + ans[cur];
    chans[i] = '\0';
    free(ans);
    return chans;
}
