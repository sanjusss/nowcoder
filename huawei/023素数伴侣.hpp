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
题目描述
若两个正整数的和为素数，则这两个正整数称之为“素数伴侣”，如2和5、6和13，它们能应用于通信加密。
现在密码学会请你设计一个程序，从已有的N（N为偶数）个正整数中挑选出若干对组成“素数伴侣”，挑选方案多种多样，
例如有4个正整数：2，5，6，13，如果将5和6分为一组中只能得到一组“素数伴侣”，而将2和5、6和13编组将得到两组“素数伴侣”，能组成“素数伴侣”最多的方案称为“最佳方案”，当然密码学会希望你寻找出“最佳方案”。

输入:
有一个正偶数N（N≤100），表示待挑选的自然数的个数。后面给出具体的数字，范围为[2,30000]。
输出:
输出一个整数K，表示你求得的“最佳方案”组成“素数伴侣”的对数。


输入描述:
1 输入一个正偶数n
2 输入n个整数

输出描述:
求得的“最佳方案”组成“素数伴侣”的对数。

示例1
输入
4
2 5 6 13
输出
2
*/

#define MAX_PRIME 60000
vector<bool> prime(MAX_PRIME + 1, true);

void initPrime()
{
	static bool initd = false;
	if (initd)
	{
		return;
	}

	initd = true;
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= MAX_PRIME; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= MAX_PRIME; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

bool dfs(int u, vector<vector<int>>& conn, vector<bool>& check, vector<int>& matching)
{
	for (int v : conn[u]) // 对 u 的每个邻接点
	{ 
		if (!check[v]) // 要求不在交替路中
		{     
			check[v] = true; // 放入交替路
			if (matching[v] == -1 || dfs(matching[v], conn, check, matching)) 
			{
				// 如果是未盖点，说明交替路为增广路，则交换路径，并返回成功
				matching[v] = u;
				matching[u] = v;
				return true;
			}
		}
	}

	return false; // 不存在增广路，返回失败
}

int main()
{
	initPrime();

    int N;
	while (cin >> N)
	{
		vector<int> nums(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> nums[i];
		}

		vector<vector<int>> conn(N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i != j && prime[nums[i] + nums[j]])
				{
					conn[i].push_back(j);
				}
			}
		}

		vector<int> matching(N, -1);
		vector<bool> check(N, false);
		int ans = 0;
		for (int u = 0; u < N; ++u)
		{
			if (nums[u] % 2 == 0)
			{
				continue;
			}

			if (matching[u] == -1)
			{
				fill(check.begin(), check.end(), false);
				if (dfs(u, conn, check, matching))
				{
					++ans;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}