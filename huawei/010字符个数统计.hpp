#pragma once

/*
��Ŀ����
��дһ�������������ַ����к��еĲ�ͬ�ַ��ĸ������ַ���ACSII�뷶Χ��(0~127)�����б�ʾ���������������ַ�����ڷ�Χ�ڵĲ���ͳ�ơ�

��������:
����N���ַ����ַ���ACSII�뷶Χ�ڡ�

�������:
�����Χ��(0~127)�ַ��ĸ�����

ʾ��1
����
abc
���
3
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
    cout << set<char>(line.begin(), line.end()).size();
    return 0;
}