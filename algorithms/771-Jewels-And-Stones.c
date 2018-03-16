// 4ms 99.42%
int numJewelsInStones(char* J, char* S) {
    int ans = 0;
    while (*S) ans += (strchr(J, (int)(*(S++))) ? 1 : 0);
    return ans;
}
