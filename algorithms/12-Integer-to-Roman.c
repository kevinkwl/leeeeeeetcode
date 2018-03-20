char* intToRoman(int num) {
    int units[] = {1000, 500, 100, 50, 10, 5, 1};
    int sub[] =   {100, 100, 10, 10, 1, 1, 0};
    char subc[] = {'C', 'C', 'X', 'X', 'I', 'I', '$'};
    char cu[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    char *ans = (char*)malloc(30 * sizeof(char));
    int idx = 0, n = 0;
    for (int i = 0; i < 7 && num > 0; i++) {
        n = num / units[i];
        for (int j = 0; j < n; j++)
            ans[idx++] = cu[i];
        num -= n * units[i];
        if (num >= units[i] - sub[i]) {
            ans[idx++] = subc[i];
            ans[idx++] = cu[i];
            num -= (units[i] - sub[i]);
        }
    }
    ans[idx] = '\0';
    return ans;
}
