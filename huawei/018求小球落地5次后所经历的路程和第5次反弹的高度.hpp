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
����һ���������߶��������£�ÿ����غ�����ԭ�߶ȵ�һ��; ������, �����ڵ�5�����ʱ��������������?��5�η�����ߣ�

��������:
������ʼ�߶ȣ�int��

�������:
�ֱ������5�����ʱ�������������׵�5�η������

ʾ��1
����
1
���
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
            l += h;//���
            if (i == count - 1)
            {
                cout << l << endl;
            }

            h /= 2;
            l += h;//����
            if (i == count - 1)
            {
                cout << h << endl;
            }

        }
    }

    return 0;
}