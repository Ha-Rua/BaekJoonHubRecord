#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
void postOrder(int start, int end);
void postOrder(int start, int end) {
    if (start > end) return;
    int root = tree[start];
    int mid = end + 1;
    for (int i = start + 1; i <= end; i++)
    {
        if (tree[i] > root)
        {
            mid = i;
            break;
        }
    }
    postOrder(start + 1, mid - 1);
    postOrder(mid, end);
    cout << root << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin >> n) tree.push_back(n);
    postOrder(0, tree.size() - 1);
    return 0;
}