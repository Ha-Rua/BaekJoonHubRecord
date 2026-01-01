#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string s; cin >> s;
    stack<char> temp;
    for (char c : s)
    {
        if (c == '(')
        {
            temp.push(c);
        }
        else if (c == ')')
        {
            while (temp.top() != '(')
            {
                cout << temp.top();
                temp.pop();
            }
            if (!temp.empty()) temp.pop();
        }
        else if (c == '+' || c == '-')
        {
            while (!temp.empty() && (temp.top() == '*' || temp.top() == '/' || temp.top() == '+' || temp.top() == '-'))
            {
                cout << temp.top();
                temp.pop();
            }
            temp.push(c);
        }
        else if (c == '*' || c == '/') 
        {
            while (!temp.empty() && (temp.top() == '*' || temp.top() == '/'))
            {
                cout << temp.top();
                temp.pop();
            }
            temp.push(c);         
        }
        else cout << c;
    }
    while (!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }
    return 0;
}