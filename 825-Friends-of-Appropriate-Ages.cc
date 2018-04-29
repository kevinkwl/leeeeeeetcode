class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int cur = ages.size() - 2, cnt = 0, total = 0;
        for (int i = ages.size() - 1; i >= 0 && cur >= 0; i--) {
            if (i == cur) {
                cur--;
                if (cur < 0)
                    break;
            }
            cnt = 0;
            // people lie in (cur, i) can also make friends with people in current extension
            int simp = max(i - cur - 1, 0);
            while (cur >= 0 && ages[cur] > ages[i] * 0.5 + 7) {
                cur--;
                cnt++;
            }
            // making friends with people in (cur, prev_cur]
            // the first term is for people lie in (prev_cur, i), the second term for cur, cur+1, cur+2, ... prev_cur, i 
            total += simp * cnt + cnt * (cnt + 1) / 2;
        }
        // handle people with same age
        for (int i = 0; i < ages.size() - 1; i++) {
            int j = i + 1;
            cnt = 0;
            while (ages[i] == ages[j]) {
                j++;
                cnt++;
            }
            if (ages[i+1] > ages[i] * 0.5 + 7)
                total += cnt * (cnt + 1) / 2;
            i = j - 1;
        }
        return total;
    }
};
