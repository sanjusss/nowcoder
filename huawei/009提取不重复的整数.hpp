#pragma once

/*
题目描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

输入描述:
输入一个int型整数

输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

示例1
输入
9876673
输出
37689
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
    int n;
    cin >> n;
    unordered_set<int> used;
    int res = 0;
    while (n > 0)
    {
        int b = n % 10;
        if (used.find(b) == used.end())
        {
            if (b != 0 || res != 0)//首位不能为0
            {
                used.insert(b);
                res = res * 10 + b;
            }
        }

        n /= 10;
    }

    cout << res;
    return 0;
}