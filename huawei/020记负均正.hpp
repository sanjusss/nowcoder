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
��������Ҫ�������������n��Ȼ������n�����������Ϊn�������и����ĸ�������������������ƽ��ֵ���������һλС����

��������:
��������һ��������n��
Ȼ������n��������

�������:
��������ĸ�������������������ƽ��ֵ��

ʾ��1
����
5
1
2
3
4
5
���
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