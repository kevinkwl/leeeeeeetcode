class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty() || path[0] != '/')
            return "";
        vector<string> paths;
        int start, end = 0;
        while((start = path.find_first_not_of('/', end)) != string::npos) {
            end = path.find_first_of('/', start);
            string dir;
            if (end == string::npos)
                dir = path.substr(start, path.size() - start);
            else
                dir = path.substr(start, end - start);
            if (dir == ".")
                continue;
            if (dir == "..") {
                if (!paths.empty())
                    paths.pop_back();
            }
            else
                paths.push_back(dir);
        }
        string ans = "";
        for (string & s : paths)
            ans += "/" + s;
        if (ans.empty())
            ans = "/";
        return ans;
    }
};
