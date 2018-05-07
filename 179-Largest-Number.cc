class Solution {
public:
    struct rsort {
        bool operator()(const string &l, const string &r)
        {
            int n = min(l.size(), r.size());
            for (int i = 0; i < n; ++i)
            {
                if (l[i] > r[i])
                    return true;
                else if (l[i] < r[i])
                    return false;
            }
            if (l.size() > r.size())
            {
                string next = l.substr(n, l.size() - n);
                return (*this)(next, r);
            }
            else if (l.size() < r.size())
            {
                string next = r.substr(n, r.size() - n);
                return (*this)(l, next);
            }
            return false;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> st;
        for (auto & i : nums)
            st.push_back(to_string(i));
        sort(st.begin(), st.end(), rsort());
        string ans;
        for (auto & w : st)
            ans += w;
        bool strip = true;
        string final;
        int i;
        for (i = 0; i < ans.size(); ++i)
            if (ans[i] != '0')
                break;
        if (i == ans.size())
            final = '0';
        else
            final = ans.substr(i, ans.size() - i);
        return final;
    }
};
