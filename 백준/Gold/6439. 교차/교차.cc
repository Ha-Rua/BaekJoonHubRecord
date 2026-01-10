#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct Point {
    long long x, y;
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
int ccw(Point p1, Point p2, Point p3) {
    long long res = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
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
    while (t--)
    {
        Point line1, line2;
        cin >> line1.x >> line1.y >> line2.x >> line2.y;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int minX = min(x1, x2);
        int minY = min(y1, y2);
        int maxX = max(x1, x2);
        int maxY = max(y1, y2);
        Point leftUp = {minX, maxY};
        Point leftDown = {minX, minY};
        Point rightUp = {maxX, maxY};
        Point rightDown = {maxX, minY};
        bool isInter = false;
        if (isIntersect({line1, line2}, {leftUp, leftDown}) || isIntersect({line1, line2}, {leftUp, rightUp}) || isIntersect({line1, line2}, {rightUp, rightDown}) || isIntersect({line1, line2}, {leftDown, rightDown}))
            isInter = true;
        else if (line1.x >= minX && line1.x <= maxX && line2.x >= minX && line2.x <= maxX && line1.y >= minY && line1.y <= maxY && line2.y >= minY && line2.y <= maxY)
            isInter = true;
        cout << (isInter ? 'T' : 'F') << '\n';
    }
    return 0;
}