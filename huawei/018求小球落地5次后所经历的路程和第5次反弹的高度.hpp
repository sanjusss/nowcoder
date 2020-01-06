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
假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？

输入描述:
输入起始高度，int型

输出描述:
分别输出第5次落地时，共经过多少米第5次反弹多高

示例1
输入
1
输出
2.875
0.03125
*/

int main()
{
    double h;
    while (cin >> h)
    {
        double l = 0;
        int count = 5;
        for (int i = 0; i < count; ++i)
        {
            l += h;//落地
            if (i == count - 1)
            {
                cout << l << endl;
            }

            h /= 2;
            l += h;//弹起
            if (i == count - 1)
            {
                cout << h << endl;
            }

        }
    }

    return 0;
}