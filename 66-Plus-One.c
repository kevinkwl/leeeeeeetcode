/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i] += carry;
        carry = digits[i] / 10;
        digits[i] %= 10;
    }
    *returnSize = carry ? digitsSize + 1 : digitsSize;
    int *res = (int *)malloc(*returnSize * sizeof(int));
    int i = 0, j = 0;
    if (carry)
        res[i++] = carry;
    while (i < *returnSize)  res[i++] = digits[j++];
    return res;
}
