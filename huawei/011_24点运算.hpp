#pragma once

/*
��Ŀ����
����24����һ���˿���������Ϸ��������4���˿��ƣ�ͨ����(+)����(-)����(*), ��(/)�������㷨�����õ�����24���������У��˿���ͨ�������ַ������ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������

                   3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER

������Ҫ��ʵ�֣�����4���ƣ����һ����ʽ����ʽ�Ľ��Ϊ24�㡣

��ϸ˵����

1.����ֻ���ǼӼ��˳����㣬û�н׳˵�����������ţ��������ѣ���������Ҫ���ģ�
2.����2~10��Ӧ��ȨֵΪ2~10, J��Q��K��AȨֵ�ֱ�ΪΪ11��12��13��1��
3.����4����Ϊ�ַ�����ʽ����һ���ո��������β�޿ո���������4�����а�����С����������ַ�����ERROR������ʾ�޷����㣻
4.�������ʽ��ʽΪ4����ͨ��+ - * / �ĸ�������������м��޿ո�4���Ƴ���˳�����⣬ֻҪ�����ȷ��
5.�����ʽ������˳��������ң����������ţ���1+2+3*4�Ľ��Ϊ24
6.������ڶ�����ʽ���ܼ���ó�24��ֻ�����һ�ּ��ɣ�����޷��ó�24���������NONE����ʾ�޽⡣

�������� :
����4����Ϊ�ַ�����ʽ����һ���ո��������β�޿ո�

������� :
��������4�����а�����С����������ַ�����ERROR������ʾ�޷����㣻
ʾ��1
����
A A A A
���
NONE
*/

/*
ţ�������ܼ����ȷ�𰸣�����
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

#pragma warning(disable:28182)
#pragma warning(disable:26451)
#pragma warning(disable:4267)
#pragma warning(disable:4244)
#pragma warning(disable:6100)
#pragma warning(disable:26495)

using namespace std;

double toNumber(char c)
{
    switch (c)
    {
    case 'J':
        return 11.0;

    case 'Q':
        return 12.0;

    case 'K':
        return 13.0;

    case 'A':
        return 1.0;

    default:
        return (c - '0') * 1.0;
    }
}

bool is24(const vector<string> &cards, const vector<char> &ops)
{
    double res = toNumber(cards[0][0]);
    for (int i = 1; i <= 3; ++i)
    {
        double next = toNumber(cards[i][0]);
        switch (ops[i - 1])
        {
        case '*':
            res *= next;
            break;

        case '/':
            res /= next;
            break;

        case '+':
            res += next;
            break;

        case '-':
            res -= next;

        default:
            break;
        }

    }
    if (res > 23.999 && res < 24.001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<string> cards(4);
    bool invalid = false;
    for (int i = 0; i < 4; ++i)
    {
        cin >> cards[i];
        if (cards[i] == "joker" ||
            cards[i] == "JOKER")
        {
            invalid = true;
        }
    }

    if (invalid)
    {
        cout << "ERROR";
    }
    else
    {
        vector<char> ops = { '+', '-', '*', '/'};
        vector<vector<char>> slns;
        for (auto i : ops)
        {
            for (auto j : ops)
            {
                for (auto k : ops)
                {
                    slns.push_back({ i, j, k });
                }
            }
        }

        std::sort(cards.begin(), cards.end());
        bool success = false;
        do
        {
            for (auto& i : slns)
            {
                if (is24(cards, i))
                {
                    cout << cards[0] << i[0] << cards[1] << i[1] << cards[2] << i[2] << cards[3];
                    success = true;
                    break;
                }
            }

            if (success)
            {
                break;
            }
        } while (next_permutation(cards.begin(), cards.end()));

        if (success == false)
        {
            cout << "NONE";
        }
    }

    return 0;
}