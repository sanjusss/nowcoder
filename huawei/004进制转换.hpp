#pragma once

/*
��Ŀ����
д��һ�����򣬽���һ��ʮ�����Ƶ������������ֵ��ʮ���Ʊ�ʾ��������ͬʱ���� ��

��������:
����һ��ʮ�����Ƶ���ֵ�ַ�����

�������:
�������ֵ��ʮ�����ַ�����

ʾ��1
����
0xA
���
10
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
    string input;
	while (cin >> input)
	{
		cout << stoi(input, nullptr, 16) << endl;
	}

	return 0;
}