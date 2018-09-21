class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, int> f2g;
        for (string &s : paths) {
            istringstream splited(s);
            string dir;
            splited >> dir;
            if (dir == "")
                continue;
            while (!splited.eof()) {
                string f;
                splited >> f;
                int i = f.find_first_of('(');
                string fname = f.substr(0, i);
                string fcontent = f.substr(i+1, f.length() - i - 2);
                string pathname = dir + '/' + fname;
                
                if (f2g.count(fcontent) > 0) {
                    res[f2g[fcontent]].push_back(pathname);
                } else {
                    res.push_back(vector<string>{pathname});
                    f2g[fcontent] = res.size() - 1;
                }
            }
        }
        res.erase(remove_if(res.begin(), res.end(), [](const vector<string> &vs) { return vs.size() == 1; })
                 , res.end());
        return res;
    }
};
