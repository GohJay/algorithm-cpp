#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    string str;
    stack<char> stack;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            cout << str[i];
        }
        else
        {
            if (str[i] == '(')
                stack.push(str[i]);
            else if (str[i] == '*' || str[i] == '/')
            {
                while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
                {
                    cout << stack.top();
                    stack.pop();
                }
                stack.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!stack.empty() && stack.top() != '(')
                {
                    cout << stack.top();
                    stack.pop();
                }
                stack.push(str[i]);
            }
            else if (str[i] == ')')
            {
                while (stack.top() != '(')
                {
                    cout << stack.top();
                    stack.pop();
                }
                stack.pop();
            }
        }
    }

    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }

    return 0;
}
