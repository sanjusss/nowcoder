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
��Ŀ����
����һ���򵥴����¼����Сģ�飬�ܹ���¼����Ĵ������ڵ��ļ����ƺ��кš�
����
1�� ��¼���8�������¼��ѭ����¼������ͬ�Ĵ����¼�����ļ����ƺ��к���ȫƥ�䣩ֻ��¼һ��������������ӣ�
2�� ����16���ַ����ļ����ƣ�ֻ��¼�ļ��������Ч16���ַ���
3�� ������ļ����ܴ�·������¼�ļ����Ʋ��ܴ�·����
��������:
һ�л�����ַ�����ÿ�а�����·���ļ����ƣ��кţ��Կո������
�������:
�����еļ�¼ͳ�Ʋ�������������ʽ���ļ��� �������� ��Ŀ��һ���ո�������磺

ʾ��1
����
E:\V1R2\product\fpgadrive.c   1325
���
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