#pragma once

/*
��Ŀ����
��������ѧУ����һЩͬѧһ����һ���ʾ���飬Ϊ��ʵ��Ŀ͹��ԣ������ü����������N��1��1000֮������������N��1000����
���������ظ������֣�ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�Ȼ���ٰ���Щ����С�������򣬰����źõ�˳��ȥ��ͬѧ�����顣
����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ���(ͬһ��������������ܻ��ж������ݣ�ϣ���������ȷ����)��

Input Param

n               ����������ĸ���

inputArray      n�����������ɵ�����


Return Value

OutputArray    ����������������

ע������������֤�����������ȷ�ԣ�������������֤������������ֹһ�顣


��������:
������У���������������ĸ�������������Ӧ����������

�������:
���ض��У������Ľ��

ʾ��1
����
11
10
20
40
32
67
40
20
89
300
400
15

���
10
15
20
32
40
67
89
300
400
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
    int count = 0;
    while (cin >> count)
    {
        set<int> nums;
        for (int i = 0; i < count; ++i)
        {
            int n;
            cin >> n;
            nums.insert(n);
        }

        for (auto i : nums)
        {
            cout << i << endl;
        }
    }

    return 0;
}