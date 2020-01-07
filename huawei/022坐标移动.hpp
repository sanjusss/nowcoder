#pragma once

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

#pragma warning(disable:28182)
#pragma warning(disable:26451)
#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:6100)
#pragma warning(disable:26495)

using namespace std;

/*
题目描述
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。

输入：
合法坐标为A(或者D或者W或者S) + 数字（两位以内）
坐标之间以;分隔。
非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
下面是一个简单的例子 如：
A10;S20;W10;D30;X;A1A;B10A11;;A10;

处理过程：
起点（0,0）
+   A10   =  （-10,0）
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  无效
+   A1A   =  无效
+   B10A11   =  无效
+  一个空 不影响
+   A10  =  (10,-10)
结果 （10， -10）

输入描述:
一行字符串

输出描述:
最终坐标，以,分隔

示例1
输入
A10;S20;W10;D30;X;A1A;B10A11;;A10;
输出
10,-10
*/

//分割字符串
std::vector<std::string> split(const std::string& s, const std::string& seperator)
{
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != std::string::npos)
    {
        std::string subString(s.substr(prev_pos, pos - prev_pos));

        output.push_back(subString);

        pos += seperator.length();
        prev_pos = pos;
    }

    output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

    return output;
}

int main()
{
    unordered_map<char, pair<int, int>> acts;
    acts['A'] = { -1, 0 };
    acts['D'] = { 1, 0 };
    acts['W'] = { 0, 1 };
    acts['S'] = { 0, -1 };

    string line;
    while (getline(cin, line))
    {
        int x = 0;
        int y = 0;
        auto moves = split(line, ";");
        for (auto& m : moves)
        {
            if (m.size() > 3 ||
                acts.find(m[0]) == acts.end())
            {
                continue;
            }

            bool isNum = true;
            int d = 0;
            for (int i = 1; i < m.size(); ++i)
            {
                if (isdigit(m[i]))
                {
                    d = d * 10 + (m[i] - '0');
                }
                else
                {
                    isNum = false;
                }
            }

            if (isNum == false)
            {
                continue;
            }

            auto act = acts[m[0]];
            x += act.first * d;
            y += act.second * d;
        }

        cout << x << "," << y << endl;
    }

    return 0;
}