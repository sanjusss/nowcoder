#pragma once

#include <iostream>
#include <memory>
#include <cstring>

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
免单统计
题目描述
某商城举办了一个促销活动，如果某顾客是某一秒内早时刻下单的顾客（可能是多个人），则可以 获取免单。请你编程计算有多少顾客可以获取免单。
解答要求 时间限制：3000ms, 内存限制：64MB 输入 输入为n行数据，每一行表示一位顾客的下单时 间。 以（年-月-日 时-分-秒.毫秒）yyyy-MM-dd HH:mm:ss.ﬀf形式给出。 
0<n<50000 2000<yyyy<2020 0<MM<=12 0<dd<=28 0<=HH<=23 0<=mm<=59 0<=ss<=59 0<=ﬀf<=999 所有输 入保证合法。
输出 输出一个整数，表示有多少顾客可以获取免单。
样例：
输入样例1
2019-01-01 00:00:00.001
2019-01-01 00:00:00.002
2019-01-01 00:00:00.003
输出样例1
1
输入样例2
2019-01-01 08:59:00.123
2019-01-01 08:59:00.123
2018-12-28 10:08:00.999
输出样例2
3
*/

int main()
{
	string prefix = "2019-01-01 00:00:00.";
	int prefixSize = prefix.size();

	unordered_map<string, map<string, int>> times;
    string line;
	string second;
	string ms;
	while (getline(cin, line))
	{
		second = line.substr(0, prefixSize);
		ms = line.substr(prefixSize);
		++times[second][ms];
	}

	int count = 0;
	for (auto& p : times)
	{
		count += p.second.begin()->second;
	}

	cout << count << endl;

	return 0;
}