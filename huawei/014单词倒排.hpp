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
对字符串中的所有单词进行倒排。

说明：

1、每个单词是以26个大写或小写英文字母构成；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

输入描述:
输入一行以空格来分隔的句子

输出描述:
输出句子的逆序

示例1
输入
I am a student
输出
student a am I
*/

int main()
{
    string line;
    getline(cin, line);
    string cur;
    vector<string> texts;
    for (auto c : line)
    {
        if (isalpha(c))
        {
            cur.push_back(c);
        }
        else if (cur.empty() == false)
        {
            texts.push_back(cur);
            cur.clear();
        }
    }
    
    if (cur.empty() == false)
    {
        texts.push_back(cur);
    }

    for (int i = texts.size() - 1; i >= 0; --i)
    {
        cout << texts[i];
        if (i == 0)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    return 0;
}