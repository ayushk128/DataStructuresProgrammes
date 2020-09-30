#include <bits/stdc++.h>
using namespace std;
bool matched(char a, char b)
{
    if (a == '{' && b == '}')
        return true;
    if (a == '[' && b == ']')
        return true;
    if (a == '(' && b == ')')
        return true;
    return false;
}
bool ParenthesisMatched(string s)
{
    stack<char> stack;
    string::iterator it;
    char popped;
    for (it = s.begin(); it != s.end(); it++)
    {
        if (*it == '{' || *it == '[' || *it == '(')
            stack.push(*it);
        else if (*it == '}' || *it == ']' || *it == ')')
        {
            if (stack.empty())
                return false;
            else
            {
                popped = stack.top();
                stack.pop();
                if (!matched(popped, *it))
                {
                    return false;
                }
            }
        }
    }
    if (stack.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    if (ParenthesisMatched(s))
        cout << "Balanced.";
    else
        cout << "Unbalanced";
}
