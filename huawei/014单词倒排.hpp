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
���ַ����е����е��ʽ��е��š�

˵����

1��ÿ����������26����д��СдӢ����ĸ���ɣ�

2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������

3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������

4��ÿ�������20����ĸ��

��������:
����һ���Կո����ָ��ľ���

�������:
������ӵ�����

ʾ��1
����
I am a student
���
student a am I
*/

int main()
{
    string line;
    getline(cin, line);
    string cur;
    vector<string> texts;
    for (auto c : line)
    {
        if (isalpha(c))
        {
            cur.push_back(c);
        }
        else if (cur.empty() == false)
        {
            texts.push_back(cur);
            cur.clear();
        }
    }
    
    if (cur.empty() == false)
    {
        texts.push_back(cur);
    }

    for (int i = texts.size() - 1; i >= 0; --i)
    {
        cout << texts[i];
        if (i == 0)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}