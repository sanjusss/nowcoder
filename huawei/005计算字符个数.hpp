#pragma once

/*
��Ŀ����
д��һ�����򣬽���һ������ĸ��������ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��

��������:
��һ������һ������ĸ�������Լ��ո���ɵ��ַ������ڶ�������һ���ַ���

�������:
��������ַ����к��и��ַ��ĸ�����

ʾ��1
����
ABCDEF
A
���
1
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
    string line;
    getline(cin, line);
    char t;
    cin >> t;
    t = toupper(t);
    int count = 0;
    for (auto i : line)
    {
        if (toupper(i) == t)
        {
            ++count;
        }
    }

    cout << count << endl;
}