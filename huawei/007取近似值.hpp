#pragma once

/*
��Ŀ����
д��һ�����򣬽���һ����������ֵ���������ֵ�Ľ�������ֵ�����С�������ֵ���ڵ���5,����ȡ����С��5��������ȡ����

��������:
����һ����������ֵ

�������:
�������ֵ�Ľ�������ֵ

ʾ��1

����
5.5

���
6
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
    double f;
    cin >> f;
    if (f >= floor(f) + 0.5)
    {
        cout << ((int)f + 1);
    }
    else
    {
        cout << (int)f;
    }

    return 0;
}