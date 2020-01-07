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
��Ŀ����
����һ��������㹤�ߣ� A��ʾ�����ƶ���D��ʾ�����ƶ���W��ʾ�����ƶ���S��ʾ�����ƶ����ӣ�0,0���㿪ʼ�ƶ����������ַ��������ȡһЩ���꣬�����������������������ļ����档

���룺
�Ϸ�����ΪA(����D����W����S) + ���֣���λ���ڣ�
����֮����;�ָ���
�Ƿ��������Ҫ���ж�������AA10;  A1A;  $%$;  YAD; �ȡ�
������һ���򵥵����� �磺
A10;S20;W10;D30;X;A1A;B10A11;;A10;

������̣�
��㣨0,0��
+   A10   =  ��-10,0��
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  ��Ч
+   A1A   =  ��Ч
+   B10A11   =  ��Ч
+  һ���� ��Ӱ��
+   A10  =  (10,-10)
��� ��10�� -10��

��������:
һ���ַ���

�������:
�������꣬��,�ָ�

ʾ��1
����
A10;S20;W10;D30;X;A1A;B10A11;;A10;
���
10,-10
*/

//�ָ��ַ���
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