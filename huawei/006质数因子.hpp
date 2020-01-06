#pragma once

/*
��Ŀ����
����:����һ�������������մ�С�����˳����������������������ӣ���180����������Ϊ2 2 3 3 5 ��

���һ��������ҲҪ�пո�

��ϸ������


�����ӿ�˵����

public String getResult(long ulDataInput)

���������

long ulDataInput�������������

����ֵ��

String


��������:
����һ��long������

�������:
���մ�С�����˳����������������������ӣ��Կո���������һ��������ҲҪ�пո�

ʾ��1
����
180
���
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