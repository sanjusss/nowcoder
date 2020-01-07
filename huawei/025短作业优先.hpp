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
某多处理器多道批处理系统一次允许将多有作业调入内存，且能并行执行，其并行数等于处理器个数。该系统采用SJF的调度方式（最短作业优先，系统在调度时，总是有限调度执行处理时间最短的作业）。
现给定处理器个数m，作业数n，每个作业的处理时间分别为t1, t2...tn.
当n>m时，首先处理时间短的m个作业进入处理器处理，其他进入等待，当某个作业处理完成时，依次从等待队列中取处理时间最短的作业进入处理。
求系统处理完所有作业的耗时为多少？
注：不考虑作业切换的消耗。

输入描述：
输入2行，第一行为2个整数（采用空格分隔），分别表示处理器个数m和作业数n；第二行输入n个整数（采用空格分隔），表示每个作业的处理时长t1, t2...tn。0<m, n<100, 0<t1, t2...tn<100。

输出描述：
输出处理总时长

示例1
输入
3 5
8 4 3 1 10

输出
13

说明
首先，执行时长为1、3、4的作业4（cpu1）、作业3（cpu2）、作业2（cpu3）进入处理。
1个时间单元后，作业4执行结束，作业1进入处理（cpu1）；
3个时间单元后，作业3执行结束，作业5进入处理（cpu1）；
4个时间单元后，作业2执行结束；
9个时间单元后，作业1执行结束；
13个时间单元后，作业5执行结束。
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
短作业优先（SJF, Shortest Job First）又称为“短进程优先”SPN(Shortest Process Next)；是对FCFS算法的改进，其目标是减少平均周转时间。
短作业优先调度算法基于这样一种思想：
运行时间短的优先调度；
如果运行时间相同则调度最先发起请求的进程。
PS:本题题面描述有误，但原题如此，不宜修改，实际优先级如下:
1)接到任务的时间；
2) 如果接收时间相同则调度 运行时间最短的任务。
等待时间：一个进程从发起请求到开始执行的时间间隔。
现在有n个进程请求cpu，每个进程用一个二元组表示：(p,q),p代表该进程发起请求的时间，p代表需要占用cpu的时间。
请计算n个进程的平均等待时间。

输入描述:
输入包含多组测试数据。
对于每组测试数据，第一行为一个整数n。
然后有n行，每行两个整数，代表上述的二元组(p,q).

保证:
2<=n<=2000,1<=p<=300,1<=q<=100.

输出描述:
对于每组数据，输出一个浮点数，代表平均等待时间，请保留4位有效数字

输入例子:
4
1 4
1 3
1 5
2 1

输出例子:
5.2500
*/

/*
测试用例的优先级如下:
1)接到任务的时间；
2) 如果接收时间相同则调度 运行时间最短的任务。
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
            time = p.first;//第一个开始的任务需要给时间初始化。
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
//按题意的优先级：
//运行时间短的优先调度；
//如果运行时间相同则调度最先发起请求的进程。
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
//            time = it->first;//第一个开始的任务需要给时间初始化。
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