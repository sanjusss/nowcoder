#pragma once

/*
��Ŀ����
����һ��int�����������մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�������

��������:
����һ��int������

�������:
���մ���������Ķ�˳�򣬷���һ�������ظ����ֵ��µ�����

ʾ��1
����
9876673
���
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
            if (b != 0 || res != 0)//��λ����Ϊ0
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