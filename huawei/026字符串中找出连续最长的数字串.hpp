#pragma once

#include <iostream>
#include <memory>
#include <cstring>

#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <iterator>
#include <string>
#include <stack>
#include <queue>
#include <random>
#include <ctime>
#include <limits>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:28182)
#pragma warning(disable:26451)
#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:6100)
#pragma warning(disable:26495)

using namespace std;

/*
链接：https://www.nowcoder.com/questionTerminal/2c81f88ecd5a4cc395b5308a99afbbec
来源：牛客网

样例输出
输出123058789，函数返回值9
输出54761，函数返回值5


输入描述:
输入一个字符串。

输出描述:
输出字符串中最长的数字字符串和它的长度。如果有相同长度的串，则要一块儿输出，但是长度还是一串的长度

示例1
输入
abcd12345ed125ss123058789
输出
123058789,9
*/

pair<int, vector<string>> maxNumLength(string& s)
{
    vector<pair<int, int>> numsIndex;
    int maxLength = 0;
    int numStart = -1;
    int length = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            ++length;
            if (numStart == -1)
            {
                numStart = i;
            }
        }
        else if(numStart >= 0)
        {
            if (length > maxLength)
            {
                maxLength = length;
                numsIndex.clear();
                numsIndex.push_back({ numStart, length });
            }
            else if (length == maxLength)
            {
                numsIndex.push_back({ numStart, length });
            }

            numStart = -1;
            length = 0;
        }
    }

    if (numStart >= 0)
    {
        if (length > maxLength)
        {
            maxLength = length;
            numsIndex.clear();
            numsIndex.push_back({ numStart, length });
        }
        else if (length == maxLength)
        {
            numsIndex.push_back({ numStart, length });
        }
    }

    vector<string> nums;
    for (auto& p : numsIndex)
    {
        nums.push_back(s.substr(p.first, p.second));
    }

    return { maxLength, nums };
}

int main()
{
    string s;
    while (cin >> s)
    {
        auto p = maxNumLength(s);
        for (auto& i : p.second)
        {
            cout << i;
        }

        cout << "," << p.first << endl;
    }

    return 0;
}