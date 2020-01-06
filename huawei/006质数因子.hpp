#pragma once

/*
题目描述
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）

最后一个数后面也要有空格

详细描述：


函数接口说明：

public String getResult(long ulDataInput)

输入参数：

long ulDataInput：输入的正整数

返回值：

String


输入描述:
输入一个long型整数

输出描述:
按照从小到大的顺序输出它的所有质数的因子，以空格隔开。最后一个数后面也要有空格。

示例1
输入
180
输出
2 2 3 3 5
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
    long n;
    cin >> n;
    
    vector<int> bases;
    for (long i = 2; i <= n && n > 1; ++i)
    {
        bool success = true;
        for (auto j : bases)
        {
            if (i % j == 0)
            {
                success = false;
                break;
            }
        }

        if (success)
        {
            bases.push_back(i);

            while (n % i == 0)
            {
                cout << i << " ";
                n /= i;
            }
        }
    }

    return 0;
}