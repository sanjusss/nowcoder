#pragma once

/*
��Ŀ����
���ݱ��¼��������������ֵ��int��Χ������������Ա�������ͬ�ļ�¼���кϲ���������ͬ��������ֵ����������㣬�������keyֵ������������

��������:
�������ֵ�Եĸ���
Ȼ������ɶԵ�index��valueֵ���Կո����

�������:
����ϲ���ļ�ֵ�ԣ����У�

ʾ��1
����
4
0 1
0 2
1 2
3 4
���
0 3
1 2
3 4
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
    int count;
    cin >> count;
    map<int, int> vs;
    for (int i = 0; i < count; ++i)
    {
        int n;
        int value;
        cin >> n >> value;
        vs[n] += value;
    }

    for (auto& p : vs)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}