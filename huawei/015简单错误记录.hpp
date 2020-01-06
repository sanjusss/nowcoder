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
题目描述
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理：
1、 记录最多8条错误记录，循环记录，对相同的错误记录（净文件名称和行号完全匹配）只记录一条，错误计数增加；
2、 超过16个字符的文件名称，只记录文件的最后有效16个字符；
3、 输入的文件可能带路径，记录文件名称不能带路径。
输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。
输出描述:
将所有的记录统计并将结果输出，格式：文件名 代码行数 数目，一个空格隔开，如：

示例1
输入
E:\V1R2\product\fpgadrive.c   1325
输出
fpgadrive.c 1325 1
*/

int main()
{
    unordered_map<string, unordered_map<int, int>> records;
    vector<pair<string, int>> q;
    string fileName;
    int lineNo;
    while (cin >> fileName >> lineNo)
    {
        fileName = fileName.substr(fileName.find_last_of('\\') + 1);
        if (records[fileName].find(lineNo) == records[fileName].end())
        {
            q.push_back({ fileName, lineNo });
        }

        ++records[fileName][lineNo];
    }

    int count = 0;
    string output;
    for (auto i = q.rbegin(); i != q.rend() && count < 8; ++i)
    {
        fileName = i->first;
        lineNo = i->second;
        int rdCount = records[fileName][lineNo];
        if (fileName.size() > 16)
        {
            fileName = fileName.substr(fileName.size() - 16);
        }

        output = fileName + " " + to_string(lineNo) + " " + to_string(rdCount) + "\n" + output;
        ++count;
    }

    cout << output;
    return 0;
}