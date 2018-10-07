// 4ms  92.17%
#define mirror(me, mid) (2*(mid) - (me))

int matched(char *ext, int len, int mid, int width) {
    int l = mid - width, r = mid + width;
    return l >= 0 && r < len && ext[l] == ext[r];
}
char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1)   return s;
    
    int ext_len = 2 * len + 1;
    char ext[2100] = {[0 ... 2099] = '#'};
    int width[2100] = {0};
    for (int i= 0 ; i < len; ++i)
        ext[2*i+1] = s[i];
    ext[ext_len] = '\0';
    int best_idx = -1, best_w = 0;
    int cur = 0, cur_w=0, mirr;
    int cur_mid = 0, cur_mid_w = 0;
    while (cur < ext_len) {
        // find the radius of longest palindrome centered at cur_mid
        while (matched(ext, ext_len, cur_mid, cur_mid_w+1))
            cur_mid_w++;
        width[cur_mid] = cur_mid_w;
        if (cur_mid_w > best_w) {
            best_idx = cur_mid;
            best_w = cur_mid_w;
        }
        // find the radius of longest palindrome centered at cur_ch (which is inside the window centered at cur_mid)
        int i, next_mid_found = 0;
        for (i = 1; i <= cur_mid_w; ++i) {
            cur = cur_mid + i;
            mirr = mirror(cur, cur_mid);
            if (i + width[mirr] < cur_mid_w)
                width[cur] = width[mirr];
            else {
                cur_mid = cur;
                cur_mid_w = cur_mid_w - i;
                next_mid_found = 1;
                break;
            }
        }
        if (!next_mid_found) {
            cur_mid = cur_mid + i;
            cur_mid_w = 0;
            cur = cur_mid;
        }
    }
    
    char *ans;
    int ans_start = (best_idx - best_w)/2, ans_len = best_w;
    s[ans_start+ans_len] = '\0';
    return &s[ans_start];
}
