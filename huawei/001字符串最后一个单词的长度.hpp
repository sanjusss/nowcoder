#pragma once
/*
��Ŀ����
�����ַ������һ�����ʵĳ��ȣ������Կո������
��������:
һ���ַ������ǿգ�����С��5000��

�������:
����N�����һ�����ʵĳ��ȡ�

ʾ��1
����
hello world
���
5
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
    string word = line.substr(line.find_last_of(' ') + 1);
    cout << word.size();

    return 0;
}