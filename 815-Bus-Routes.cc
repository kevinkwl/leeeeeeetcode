// bfs
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        unordered_map<int, vector<int>> busAtStop;
        bool taken[501] = {false};
        for (int r = 0; r < routes.size(); r++)
            for (int s = 0; s < routes[r].size(); s++) {
                int stop = routes[r][s];
                if (busAtStop.count(stop) == 0)
                    busAtStop[stop] = vector<int>{};
                busAtStop[stop].push_back(r);
            }
        
        int dist = 0, len;
        queue<int> reach;
        reach.push(S);
        while (!reach.empty()) {
            dist++;             // at each loop, stops can be arrived at a cost of dist
            len = reach.size(); // process all previously arrived stops
            while (len--) {
                int s = reach.front();
                reach.pop();
                for (int bus : busAtStop[s]) {  // try every bus stopped at current stop
                    if (taken[bus]) continue;   // previously taken buses are ignored
                    taken[bus] = true;
                    for (int stop : routes[bus]) {
                        if (stop == T)  return dist;
                        reach.push(stop);       // add stops to be processed at next loop
                    }
                }
            }
        }
        return -1;
    }
};
