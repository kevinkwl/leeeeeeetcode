/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res = 0;
        unordered_map<int, unordered_map<int, int>> pts;
        for (int i = 0; i < points.size(); i++) {
            pts.clear();
            int dup = 0, maxp = 0;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;
                    continue;
                }
                int dy = points[j].y - points[i].y;
                int dx = points[j].x - points[i].x;
                int dg = gcd(dx, dy);
                if (dg != 0) {
                    dx /= dg;
                    dy /= dg;
                }
                if (pts.count(dx) == 0) {
                    unordered_map<int, int> dxMap;
                    pts[dx] = dxMap;
                    pts[dx][dy] = 1;
                } 
                else if (pts[dx].count(dy) == 0) 
                    pts[dx][dy] = 1;
                else
                    pts[dx][dy]++;
                maxp = max(maxp, pts[dx][dy]);
            }
            res = max(res, maxp + dup + 1);
        }
        return res;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
