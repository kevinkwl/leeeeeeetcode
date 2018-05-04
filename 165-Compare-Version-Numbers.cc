class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1, p2, e1, e2, v1, v2;
        p1 = p2 = e1 = e2 = 0;
        while (p1 < version1.size() || p2 < version2.size()) {
            while (e1 < version1.size() && version1[e1] != '.')
                e1++;
            while (e2 < version2.size() && version2[e2] != '.')
                e2++;
            v1 = p1 < version1.size() ? stoi(version1.substr(p1, e1 - p1)) : 0;
            v2 = p2 < version2.size() ? stoi(version2.substr(p2, e2 - p2)) : 0;
            if (v1 - v2 != 0)
                return v1 > v2 ? 1 : -1;
            p1 = e1++;
            p2 = e2++;
            if (p1 < version1.size())
                p1++;
            if (p2 < version2.size())
                p2++;
        }
        return 0;
    }
};
