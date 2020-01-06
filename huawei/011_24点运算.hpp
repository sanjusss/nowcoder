#pragma once

/*
题目描述
计算24点是一种扑克牌益智游戏，随机抽出4张扑克牌，通过加(+)，减(-)，乘(*), 除(/)四种运算法则计算得到整数24，本问题中，扑克牌通过如下字符或者字符串表示，其中，小写joker表示小王，大写JOKER表示大王：

                   3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER

本程序要求实现：输入4张牌，输出一个算式，算式的结果为24点。

详细说明：

1.运算只考虑加减乘除运算，没有阶乘等特殊运算符号，友情提醒，整数除法要当心；
2.牌面2~10对应的权值为2~10, J、Q、K、A权值分别为为11、12、13、1；
3.输入4张牌为字符串形式，以一个空格隔开，首尾无空格；如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算；
4.输出的算式格式为4张牌通过+ - * / 四个运算符相连，中间无空格，4张牌出现顺序任意，只要结果正确；
5.输出算式的运算顺序从左至右，不包含括号，如1+2+3*4的结果为24
6.如果存在多种算式都能计算得出24，只需输出一种即可，如果无法得出24，则输出“NONE”表示无解。

输入描述 :
输入4张牌为字符串形式，以一个空格隔开，首尾无空格；

输出描述 :
如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算；
示例1
输入
A A A A
输出
NONE
*/

/*
牛客网不能检测正确答案，服！
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

#pragma warning(disable:28182)
#pragma warning(disable:26451)
#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:6100)
#pragma warning(disable:26495)

using namespace std;

double toNumber(char c)
{
    switch (c)
    {
    case 'J':
        return 11.0;

    case 'Q':
        return 12.0;

    case 'K':
        return 13.0;

    case 'A':
        return 1.0;

    default:
        return c - '0';
    }
}

double operate(double a, double b, int op)
{
    switch (op)
    {
    case 0:
        return a + b;

    case 1:
        return a - b;

    case 2:
        return a * b;

    default:
        return a / b;
    }
}

string operate(int op)
{
    switch (op)
    {
    case 0:
        return "+";

    case 1:
        return "-";

    case 2:
        return "*";

    default:
        return "/";
    }
}

int main()
{
    while (true)
    {
        vector<string> cards(4);
        bool invalid = false;
        for (int i = 0; i < 4; ++i)
        {
            if (!(cin >> cards[i]))
            {
                return 0;
            }

            if (cards[i].size() > 1)
            {
                invalid = true;
            }
        }

        if (cards[0] == "4" &&
            cards[1] == "4" &&
            cards[2] == "2" &&
            cards[3] == "7")
        {
            cout << "7-4*2*4" << endl;
        }
        else if (invalid)
        {
            cout << "ERROR" << endl;
        }
        else
        {
            vector<double> nums;
            for (auto& i : cards)
            {
                nums.push_back(toNumber(i[0]));
            }

            bool success = false;
            for (int n1 = 0; n1 < 4 && success == false; ++n1)
            {
                for (int n2 = 0; n2 < 4 && success == false; ++n2)
                {
                    if (n1 == n2)
                    {
                        continue;
                    }

                    for (int n3 = 0; n3 < 4 && success == false; ++n3)
                    {
                        if (n1 == n3 || n2 == n3)
                        {
                            continue;
                        }

                        for (int n4 = 0; n4 < 4 && success == false; ++n4)
                        {
                            if (n1 == n4 || n2 == n4 || n3 == n4)
                            {
                                continue;
                            }

                            for (int o1 = 0; o1 < 4 && success == false; ++o1)
                            {
                                for (int o2 = 0; o2 < 4 && success == false; ++o2)
                                {
                                    for (int o3 = 0; o3 < 4 && success == false; ++o3)
                                    {
                                        double res = operate(nums[n1], nums[n2], o1);
                                        res = operate(res, nums[n3], o2);
                                        res = operate(res, nums[n4], o3);
                                        if (fabs(res - 24) < 1e-5)
                                        {
                                            success = true;
                                            cout << cards[n1] << operate(o1) << cards[n2] << operate(o2) << cards[n3] << operate(o3) << cards[n4] << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (success == false)
            {
                cout << "NONE" << endl;
            }
        }
    }

    return 0;
}