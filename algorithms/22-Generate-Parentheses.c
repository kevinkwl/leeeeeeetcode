// 0ms 100%

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** gen(char **sol, int *solSize, char *curStr, int n, int open, int close, int depth)
{
    if (depth == 2*n) {
        sol = (char **)realloc(sol, (*solSize+1)*sizeof(char*));
        sol[*solSize] = (char*)malloc((2*n+1)*sizeof(char));
        strcpy(sol[(*solSize)++], curStr);
        return sol;
    } else {
        if (open > 0) {
            curStr[depth] = ')';
            sol = gen(sol, solSize, curStr, n, open-1, close+1, depth+1);
        }
        if (open + close < n) {
            curStr[depth] = '(';
            sol = gen(sol, solSize, curStr, n, open+1, close, depth+1);
        }
    }
    return sol;
}
char** generateParenthesis(int n, int* returnSize) {
    char **sol;
    char *curStr = (char*)malloc((2*n+1) * sizeof(char));
    curStr[2*n] = '\0';
    int solSize = 0;
    sol = gen(sol, &solSize, curStr, n, 0, 0, 0);
    free(curStr);
    *returnSize = solSize;
    return sol;
}
