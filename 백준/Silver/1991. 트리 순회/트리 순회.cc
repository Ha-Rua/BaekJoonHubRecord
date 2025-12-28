//1991
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char Left;
    char Right;
};
Node tree[26];

void preorder(char node)
{
    if (node == '.') return;

    cout << node;
    preorder(tree[node - 'A'].Left);
    preorder(tree[node - 'A'].Right);

}

void inorder(char node)
{
    if (node == '.') return;

    inorder(tree[node - 'A'].Left);
    cout << node;    
    inorder(tree[node - 'A'].Right);
}

void postorder(char node)
{
    if (node == '.') return;

    postorder(tree[node - 'A'].Left);
    postorder(tree[node - 'A'].Right);
    cout << node;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        char x, y, z; cin >> x >> y >> z;
        tree[x - 'A'].Left = y;
        tree[x - 'A'].Right = z;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

    return 0;
}