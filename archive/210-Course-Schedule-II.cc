class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> schd;
        if (numCourses == 0) return schd;
        vector<int> in(numCourses, 0);
        vector<vector<int>> preto(numCourses, vector<int>{});
        for (pair<int, int>& pp : prerequisites) {
            in[pp.first]++;
            preto[pp.second].push_back(pp.first);
        }
        int taken = 0;
        while (taken != numCourses) {
            int cid;
            for (cid = 0; cid < numCourses; cid++)
                if (in[cid] == 0)
                    break;
            if (cid == numCourses)
                return vector<int>{};
            schd.push_back(cid);
            in[cid]--;
            for (int c : preto[cid])
                in[c]--;
            taken++;
        }
        return schd;
    }
};
