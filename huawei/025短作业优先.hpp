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
ĳ�ദ�������������ϵͳһ������������ҵ�����ڴ棬���ܲ���ִ�У��䲢�������ڴ�������������ϵͳ����SJF�ĵ��ȷ�ʽ�������ҵ���ȣ�ϵͳ�ڵ���ʱ���������޵���ִ�д���ʱ����̵���ҵ����
�ָ�������������m����ҵ��n��ÿ����ҵ�Ĵ���ʱ��ֱ�Ϊt1, t2...tn.
��n>mʱ�����ȴ���ʱ��̵�m����ҵ���봦����������������ȴ�����ĳ����ҵ�������ʱ�����δӵȴ�������ȡ����ʱ����̵���ҵ���봦��
��ϵͳ������������ҵ�ĺ�ʱΪ���٣�
ע����������ҵ�л������ġ�

����������
����2�У���һ��Ϊ2�����������ÿո�ָ������ֱ��ʾ����������m����ҵ��n���ڶ�������n�����������ÿո�ָ�������ʾÿ����ҵ�Ĵ���ʱ��t1, t2...tn��0<m, n<100, 0<t1, t2...tn<100��

���������
���������ʱ��

ʾ��1
����
3 5
8 4 3 1 10

���
13

˵��
���ȣ�ִ��ʱ��Ϊ1��3��4����ҵ4��cpu1������ҵ3��cpu2������ҵ2��cpu3�����봦��
1��ʱ�䵥Ԫ����ҵ4ִ�н�������ҵ1���봦��cpu1����
3��ʱ�䵥Ԫ����ҵ3ִ�н�������ҵ5���봦��cpu1����
4��ʱ�䵥Ԫ����ҵ2ִ�н�����
9��ʱ�䵥Ԫ����ҵ1ִ�н�����
13��ʱ�䵥Ԫ����ҵ5ִ�н�����
*/

//int sjf(vector<int>& jobs, int m)
//{
//    sort(jobs.begin(), jobs.end());
//    multiset<int> cpus;
//    for (auto i : jobs)
//    {
//        if (cpus.size() < m)
//        {
//            cpus.insert(i);
//        }
//        else
//        {
//            int time = i + *cpus.begin();
//            cpus.erase(cpus.begin());
//            cpus.insert(time);
//        }
//    }
//
//    return *cpus.rbegin();
//}
//
//int main()
//{
//    int m;
//    int n;
//    while (cin >> m >> n)
//    {
//        vector<int> jobs(n);
//        for (int i = 0; i < n; ++i)
//        {
//            cin >> jobs[i];
//        }
//
//        cout << sjf(jobs, m) << endl;
//    }
//
//    return 0;
//}

/*
����ҵ���ȣ�SJF, Shortest Job First���ֳ�Ϊ���̽������ȡ�SPN(Shortest Process Next)���Ƕ�FCFS�㷨�ĸĽ�����Ŀ���Ǽ���ƽ����תʱ�䡣
����ҵ���ȵ����㷨��������һ��˼�룺
����ʱ��̵����ȵ��ȣ�
�������ʱ����ͬ��������ȷ�������Ľ��̡�
PS:���������������󣬵�ԭ����ˣ������޸ģ�ʵ�����ȼ�����:
1)�ӵ������ʱ�䣻
2) �������ʱ����ͬ����� ����ʱ����̵�����
�ȴ�ʱ�䣺һ�����̴ӷ������󵽿�ʼִ�е�ʱ������
������n����������cpu��ÿ��������һ����Ԫ���ʾ��(p,q),p����ý��̷��������ʱ�䣬p������Ҫռ��cpu��ʱ�䡣
�����n�����̵�ƽ���ȴ�ʱ�䡣

��������:
�����������������ݡ�
����ÿ��������ݣ���һ��Ϊһ������n��
Ȼ����n�У�ÿ���������������������Ķ�Ԫ��(p,q).

��֤:
2<=n<=2000,1<=p<=300,1<=q<=100.

�������:
����ÿ�����ݣ����һ��������������ƽ���ȴ�ʱ�䣬�뱣��4λ��Ч����

��������:
4
1 4
1 3
1 5
2 1

�������:
5.2500
*/

/*
�������������ȼ�����:
1)�ӵ������ʱ�䣻
2) �������ʱ����ͬ����� ����ʱ����̵�����
*/
double sjf(vector<pair<int, int>>& jobs)
{
    map<int, multiset<int>> table;
    for (auto& job : jobs)
    {
        table[job.first].insert(job.second);
    }

    int time = 0;
    int wait = 0;
    while (table.empty() == false)
    {
        auto& p = *table.begin();
        if (time > p.first)
        {
            wait += time - p.first;
        }
        else
        {
            time = p.first;//��һ����ʼ��������Ҫ��ʱ���ʼ����
        }

        time += *p.second.begin();
        p.second.erase(p.second.begin());
        if (p.second.empty())
        {
            table.erase(table.begin());
        }
    }

    return (double)wait / (double)jobs.size();
}

///*
//����������ȼ���
//����ʱ��̵����ȵ��ȣ�
//�������ʱ����ͬ��������ȷ�������Ľ��̡�
//*/
//double sjf(vector<pair<int, int>>& jobs)
//{
//    map<int, multiset<int>> table;
//    for (auto& job : jobs)
//    {
//        table[job.first].insert(job.second);
//    }
//
//    int time = 0;
//    int wait = 0;
//    while (table.empty() == false)
//    {
//        auto end = table.upper_bound(time);
//        auto it = table.begin();
//        for (auto i = table.begin(); i != end; ++i)
//        {
//            if ((*i->second.begin()) < (*it->second.begin()))
//            {
//                it = i;
//            }
//        }
//
//        if (time > it->first)
//        {
//            wait += time - it->first;
//        }
//        else
//        {
//            time = it->first;//��һ����ʼ��������Ҫ��ʱ���ʼ����
//        }
//
//        time += *it->second.begin();
//        it->second.erase(it->second.begin());
//        if (it->second.empty())
//        {
//            table.erase(it);
//        }
//    }
//
//    return (double)wait / (double)jobs.size();
//}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> jobs[i].first >> jobs[i].second;
        }

        double ans = sjf(jobs);
        printf("%.4f\n", ans);
    }

    return 0;
}