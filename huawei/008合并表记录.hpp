#pragma once

/*
题目描述
数据表记录包含表索引和数值（int范围的整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述:
先输入键值对的个数
然后输入成对的index和value值，以空格隔开

输出描述:
输出合并后的键值对（多行）

示例1
输入
4
0 1
0 2
1 2
3 4
输出
0 3
1 2
3 4
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
    int count;
    cin >> count;
    map<int, int> vs;
    for (int i = 0; i < count; ++i)
    {
        int n;
        int value;
        cin >> n >> value;
        vs[n] += value;
    }

    for (auto& p : vs)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}