class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses < 2) return true;
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
                return false;
            in[cid]--;
            for (int c : preto[cid])
                in[c]--;
            taken++;
        }
        return true;
    }
};
