#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n;

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

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }
    void unionSets(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
            {
                parent[a] = b;
                size[b] += size[a];
            }
            else if (rank[a] > rank[b])
            {
                parent[b] = a;
                size[a] += size[b];
            }
            else {
                parent[b] = a;
                rank[a]++;
                size[a] += size[b];
            }
        }
    }
    int getSize(int x)
    {
        return size[find(x)];
    }
private:
    vector<int> parent, rank, size;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; vector<pair<Point, Point>> lines(n);
    UnionFind uf(n);
    for (int i = 0; i < n; i++)  cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isIntersect(lines[i], lines[j])) uf.unionSets(i, j);
        }
    }
    int Groups = 0;
    int maxGroupSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (uf.find(i) == i)
        {
            Groups++;
            maxGroupSize = max(maxGroupSize, uf.getSize(i));
        }
    }
    cout << Groups << '\n' << maxGroupSize;
    return 0;
}