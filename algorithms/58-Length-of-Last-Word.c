int lengthOfLastWord(char* s) {
    int len = strlen(s);
    char *end = s + len;
    char *st, *ed;
    while (end != s && *(end-1) == ' ') end--;
    ed = end;
    while (end != s && *(end-1) != ' ') end--;
    st = end;
    return ed - st;
}
