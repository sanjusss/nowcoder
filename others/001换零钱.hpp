#pragma once
#include "newcoder.h"

/*
链接：https://www.nowcoder.com/questionTerminal/185dc37412de446bbfff6bd21e4356ec
来源：牛客网

有一个数组changes，changes中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，对于一个给定值x，请设计一个高效算法，计算组成这个值的方案数。

给定一个int数组changes，代表所有零钱，同时给定它的大小n，另外给定一个正整数x，请返回组成x的方案数，保证n小于等于100且x小于等于10000。

测试样例：
[5,10,25,1],4,15
返回：6
测试样例：
[5,10,25,1],4,0
返回：1
*/

class Exchange 
{
public:
    int countWays(vector<int> changes, int n, int x) 
    {
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int c : changes)
        {
            for (int i = c; i <= x; ++i)
            {
                dp[i] += dp[i - c];
            }
        }

        return dp[x];
    }
};