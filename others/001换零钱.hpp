#pragma once
#include "newcoder.h"

/*
���ӣ�https://www.nowcoder.com/questionTerminal/185dc37412de446bbfff6bd21e4356ec
��Դ��ţ����

��һ������changes��changes�����е�ֵ��Ϊ�����Ҳ��ظ���ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ�����һ������ֵx�������һ����Ч�㷨������������ֵ�ķ�������

����һ��int����changes������������Ǯ��ͬʱ�������Ĵ�Сn���������һ��������x���뷵�����x�ķ���������֤nС�ڵ���100��xС�ڵ���10000��

����������
[5,10,25,1],4,15
���أ�6
����������
[5,10,25,1],4,0
���أ�1
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