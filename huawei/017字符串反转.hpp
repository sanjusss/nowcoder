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
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
��������:
����N���ַ�

�������:
������ַ�����ת����ַ���

ʾ��1
����
abcd
���
dcba
*/

int main()
{
    string num;
    cin >> num;
    for (auto i = num.rbegin(); i != num.rend(); ++i)
    {
        cout << *i;
    }

    return 0;
}