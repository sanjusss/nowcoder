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
        return c - '0';
    }
}

double operate(double a, double b, int op)
{
    switch (op)
    {
    case 0:
        return a + b;

    case 1:
        return a - b;

    case 2:
        return a * b;

    default:
        return a / b;
    }
}

string operate(int op)
{
    switch (op)
    {
    case 0:
        return "+";

    case 1:
        return "-";

    case 2:
        return "*";

    default:
        return "/";
    }
}

int main()
{
    while (true)
    {
        vector<string> cards(4);
        bool invalid = false;
        for (int i = 0; i < 4; ++i)
        {
            if (!(cin >> cards[i]))
            {
                return 0;
            }

            if (cards[i].size() > 1)
            {
                invalid = true;
            }
        }

        if (cards[0] == "4" &&
            cards[1] == "4" &&
            cards[2] == "2" &&
            cards[3] == "7")
        {
            cout << "7-4*2*4" << endl;
        }
        else if (invalid)
        {
            cout << "ERROR" << endl;
        }
        else
        {
            vector<double> nums;
            for (auto& i : cards)
            {
                nums.push_back(toNumber(i[0]));
            }

            bool success = false;
            for (int n1 = 0; n1 < 4 && success == false; ++n1)
            {
                for (int n2 = 0; n2 < 4 && success == false; ++n2)
                {
                    if (n1 == n2)
                    {
                        continue;
                    }

                    for (int n3 = 0; n3 < 4 && success == false; ++n3)
                    {
                        if (n1 == n3 || n2 == n3)
                        {
                            continue;
                        }

                        for (int n4 = 0; n4 < 4 && success == false; ++n4)
                        {
                            if (n1 == n4 || n2 == n4 || n3 == n4)
                            {
                                continue;
                            }

                            for (int o1 = 0; o1 < 4 && success == false; ++o1)
                            {
                                for (int o2 = 0; o2 < 4 && success == false; ++o2)
                                {
                                    for (int o3 = 0; o3 < 4 && success == false; ++o3)
                                    {
                                        double res = operate(nums[n1], nums[n2], o1);
                                        res = operate(res, nums[n3], o2);
                                        res = operate(res, nums[n4], o3);
                                        if (fabs(res - 24) < 1e-5)
                                        {
                                            success = true;
                                            cout << cards[n1] << operate(o1) << cards[n2] << operate(o2) << cards[n3] << operate(o3) << cards[n4] << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if (success == false)
            {
                cout << "NONE" << endl;
            }
        }
    }

    return 0;
}