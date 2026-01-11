#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

struct Point {
    double x, y;
    bool operator<(const Point& other) const
    {
        if (x != other.x) return x < other.x;
        else return y < other.y;
    }
    bool operator<=(const Point& other) const
    {
        if (x != other.x) return x < other.x;
        else return y <= other.y;        
    }
};

double getDist(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(Point p1, Point p2, Point p3) {
    double res = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

bool isIntersect(pair<Point, Point> l1, pair<Point, Point> l2)
{
    Point p1 = l1.first;
    Point p2 = l1.second;
    Point p3 = l2.first;
    Point p4 = l2.second;
    
    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0)
    {
        if (p2 < p1) swap(p2, p1);
        if (p4 < p3) swap(p3, p4);
        return p3 <= p2 && p1 <= p4;    
    }
    return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, r, p; cin >> n >> r >> p;
        vector<Point> points(n);
        for (int j = 0; j < n; j++) cin >> points[j].x >> points[j].y;
        vector<Point> routers(r);
        for (int j = 0; j < r; j++) cin >> routers[j].x >> routers[j].y;
        vector<Point> locations(p);
        for (int j = 0; j < p; j++) cin >> locations[j].x >> locations[j].y;
        vector<double> res;
        for (int j = 0; j < p; j++)
        {
            double curMax = 0.0;
            for (int k = 0; k < r; k++)
            {
                bool isBlocked = false;
                for (int l = 0; l < n; l++)
                {
                    if (isIntersect({points[l], points[(l + 1) % n]}, {locations[j], routers[k]})) 
                    {
                        isBlocked = true;
                        break;
                    }
                }
                if (isBlocked) continue;
                curMax = max(curMax, 1 / (getDist(locations[j], routers[k])));
            }
            res.push_back(curMax);
        }
        cout << "Data Set " << i << ':' << '\n';
        for (double a : res) cout << fixed << setprecision(2) << a << '\n';
    }
    return 0;
}