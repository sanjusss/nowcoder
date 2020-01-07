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
��Ŀ����
�������������ĺ�Ϊ����������������������֮Ϊ���������¡�����2��5��6��13��������Ӧ����ͨ�ż��ܡ�
��������ѧ���������һ�����򣬴����е�N��NΪż����������������ѡ�����ɶ���ɡ��������¡�����ѡ�������ֶ�����
������4����������2��5��6��13�������5��6��Ϊһ����ֻ�ܵõ�һ�顰�������¡�������2��5��6��13���齫�õ����顰�������¡�������ɡ��������¡����ķ�����Ϊ����ѷ���������Ȼ����ѧ��ϣ����Ѱ�ҳ�����ѷ�������

����:
��һ����ż��N��N��100������ʾ����ѡ����Ȼ���ĸ��������������������֣���ΧΪ[2,30000]��
���:
���һ������K����ʾ����õġ���ѷ�������ɡ��������¡��Ķ�����


��������:
1 ����һ����ż��n
2 ����n������

�������:
��õġ���ѷ�������ɡ��������¡��Ķ�����

ʾ��1
����
4
2 5 6 13
���
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
	for (int v : conn[u]) // �� u ��ÿ���ڽӵ�
	{ 
		if (!check[v]) // Ҫ���ڽ���·��
		{     
			check[v] = true; // ���뽻��·
			if (matching[v] == -1 || dfs(matching[v], conn, check, matching)) 
			{
				// �����δ�ǵ㣬˵������·Ϊ����·���򽻻�·���������سɹ�
				matching[v] = u;
				matching[u] = v;
				return true;
			}
		}
	}

	return false; // ����������·������ʧ��
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