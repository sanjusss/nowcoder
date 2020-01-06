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
描述：

输入一个整数，将这个整数以字符串的形式逆序输出

程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001


输入描述:
输入一个int整数

输出描述:
将这个整数以字符串的形式逆序输出

示例1
输入
1516000
输出
0006151
*/

int main()
{
    string num;
    cin >> num;
    for (auto i = num.rbegin(); i != num.rend(); ++i)
    {
        cout << *i;
    }

    return 0;
}