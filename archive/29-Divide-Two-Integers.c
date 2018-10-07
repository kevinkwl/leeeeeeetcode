// O(1)
int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX; // overflow
    int neg = (dividend > 0) ^ (divisor > 0);
    
    unsigned int dd = llabs(dividend);
    unsigned int ds = llabs(divisor);
    int q = 0;
    
    for (int i = (sizeof(int) << 3) - 1; i >= 0; i--) {
        if ((dd >> i) >= ds) {
            q = (q << 1) | 0x1;
            dd -= (ds << i);
        }
        else
            q <<= 1;
    }
    return neg ? -q : q;
}
// O(log(n)^2)
int divide2(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX; // overflow
    int neg = (dividend > 0) ^ (divisor > 0);
    long long q = 0, i = 0;
    long long dd = llabs(dividend);
    long long ds = llabs(divisor);
    while (ds <= dd) {
        i = 0;
        while ((ds << i) <= dd) i++;
        q += ((long long)1 << (i - 1));
        dd -= (ds << (i - 1));
    }
    return neg ? -q : q;
}
