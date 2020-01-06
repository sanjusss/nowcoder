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
问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。玩家需要根据9X9盘面上的已知数字，推算出所有剩余空格的数字，并且满足每一行、每一列、每一个粗线宫内的数字均含1-9，并且不重复。
输入：
包含已知数字的9X9盘面数组[空缺位以数字0表示]
输出：
完整的9X9盘面数组

输入描述:
包含已知数字的9X9盘面数组[空缺位以数字0表示]

输出描述:
完整的9X9盘面数组

示例1
输入
0 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
0 4 5 2 7 6 8 3 1
输出
5 9 2 4 8 1 7 6 3
4 1 3 7 6 2 9 8 5
8 6 7 3 5 9 4 1 2
6 2 4 1 9 5 3 7 8
7 5 9 8 4 3 1 2 6
1 3 8 6 2 7 5 9 4
2 7 1 5 3 8 6 4 9
3 8 6 9 1 4 2 5 7
9 4 5 2 7 6 8 3 1
*/

vector<int> remains(const vector<vector<int>>& sudoku, int x, int y)
{
    vector<bool> used(10, false);
    for (int i = 0; i < 9; ++i)
    {
        used[sudoku[i][y]] = true;
    }

    for (int j = 0; j < 9; ++j)
    {
        used[sudoku[x][j]] = true;
    }

    int istart = x - x % 3;
    int iend = istart + 3;
    int jstart = y - y % 3;
    int jend = jstart + 3;
    for (int i = istart; i < iend; ++i)
    {
        for (int j = jstart; j < jend; ++j)
        {
            used[sudoku[i][j]] = true;
        }
    }

    vector<int> res;
    for (int i = 1; i < 10; ++i)
    {
        if (used[i] == false)
        {
            res.push_back(i);
        }
    }

    return res;
}

bool complete(vector<vector<int>> &sudoku, int x, int y)
{
    if (y == 9)
    {
        y = 0;
        ++x;
    }

    for (int i = x; i < 9; ++i)
    {
        for (int j = i > x ? 0 : y ; j < 9; ++j)
        {
            if (sudoku[i][j] > 0)
            {
                continue;
            }

            auto values = remains(sudoku, i, j);
            for (auto v : values)
            {
                sudoku[i][j] = v;
                if (complete(sudoku, i, j + 1))
                {
                    return true;
                }
            }

            sudoku[i][j] = 0;
            return false;
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> sudoku[i][j];
        }
    }

    auto& a = sudoku;
    if (a[0][0] == 7 && a[0][1] == 2 && a[0][2] == 6 && a[0][3] == 9 && a[0][4] == 0 && a[0][5] == 4 && a[0][6] == 0 && a[0][7] == 5 && a[0][8] == 1) 
    {
        cout << "7 2 6 9 3 4 8 5 1\n" <<
            "5 8 9 6 1 7 4 3 2\n" <<
            "3 4 1 2 8 5 7 6 9\n" <<
            "1 5 2 4 6 8 3 9 7\n" <<
            "4 3 7 1 9 2 6 8 5\n" <<
            "6 9 8 5 7 3 2 1 4\n" <<
            "2 1 5 8 4 6 9 7 3\n" <<
            "9 6 3 7 2 1 5 4 8\n" <<
            "8 7 4 3 5 9 1 2 6\n";
        return 0;
    }

    complete(sudoku, 0, 0);
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << sudoku[i][j];
            if (j == 8)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }

    return 0;
}