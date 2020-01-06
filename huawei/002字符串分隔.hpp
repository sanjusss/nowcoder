#pragma once

/*
题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组

示例1
输入
abc
123456789

输出
abc00000
12345678
90000000
*/

#include <iostream>

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

using namespace std;

int main()
{
    int maxInput = 2;
    vector<string> texts(maxInput);
    for (int i = 0; i < 2; ++i)
    {
        cin >> texts[i];
    }

    for (auto& s : texts)
    {
        for (int i = 0; i < s.size(); i += 8)
        {
            string res = s.substr(i, 8);
            if (res.size() < 8)
            {
                res.insert(res.size(), 8 - res.size(), '0');
            }

            cout << res << endl;
        }
    }

    return 0;
}