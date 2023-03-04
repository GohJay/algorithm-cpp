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
	string bomb;
	cin >> str;
	cin >> bomb;

    vector<char> vect;
    vect.reserve(1000000);

    for (int i = 0; i < str.size(); i++)
    {
        vect.push_back(str[i]);

        if (vect.size() >= bomb.size())
        {
            bool flag = true;
            for (int i = 0; i < bomb.size(); i++)
            {
                // 문자열 폭탄인지 판별
                if (vect[vect.size() - bomb.size() + i] != bomb[i])
                {
                    flag = false;
                    break;
                }
            }

            // 문자열 폭발
            if (flag)
            {
                for (int i = 0; i < bomb.size(); i++)
                {
                    vect.pop_back();
                }
            }
        }
    }

    if (!vect.empty())
    {
        for (int i = 0; i < vect.size(); i++)
            cout << vect[i];
    }
    else
        cout << "FRULA" << endl;

	return 0;
}
