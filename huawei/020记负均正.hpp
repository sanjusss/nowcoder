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
首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。

输入描述:
首先输入一个正整数n，
然后输入n个整数。

输出描述:
输出负数的个数，和所有正整数的平均值。

示例1
输入
5
1
2
3
4
5
输出
0 3
*/

int main()
{
    int count;
    while (cin >> count)
    {
        int sum = 0;
        int sumCount = 0;
        int ncount = 0;
        int num;
        for (int i = 0; i < count; ++i)
        {
            cin >> num;
            if (num > 0)
            {
                sum += num;
                ++sumCount;
            }
            else if (num < 0)
            {
                ++ncount;
            }
        }

        double avg = sumCount == 0 ? 0 : (double)sum / (double)sumCount;
        printf("%d %0.1f\n", ncount, avg);
    }

    return 0;
}