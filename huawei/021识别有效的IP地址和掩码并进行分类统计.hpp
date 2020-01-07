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
�����IP��ַ�Ͷ�Ӧ�����룬���з���ʶ��Ҫ����A/B/C/D/E���ַ���࣬���Ϸ��ĵ�ַ�����뵥�����ࡣ

���е�IP��ַ����Ϊ A,B,C,D,E����

A���ַ1.0.0.0~126.255.255.255;

B���ַ128.0.0.0~191.255.255.255;

C���ַ192.0.0.0~223.255.255.255;

D���ַ224.0.0.0~239.255.255.255��

E���ַ240.0.0.0~255.255.255.255


˽��IP��Χ�ǣ�

10.0.0.0��10.255.255.255

172.16.0.0��172.31.255.255

192.168.0.0��192.168.255.255


��������Ϊ��������ǰ����������1��Ȼ��ȫ��0�������磺255.255.255.32����һ���Ƿ������룩

��������:
�����ַ�����ÿ��һ��IP��ַ�����룬��~������

�������:
ͳ��A��B��C��D��E������IP��ַ��������롢˽��IP�ĸ�����֮���Կո������

ʾ��1
����
10.70.44.68~255.254.255.0
1.0.0.1~255.0.0.0
192.168.0.2~255.255.255.0
19..0.~255.255.255.0
���
1 0 1 0 0 2 1
*/

//�ָ��ַ���
std::vector<std::string> split(const std::string& s, const std::string& seperator)
{
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != std::string::npos)
    {
        std::string subString(s.substr(prev_pos, pos - prev_pos));

        output.push_back(subString);

        pos += seperator.length();
        prev_pos = pos;
    }

    output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

    return output;
}

int main()
{
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int E = 0;
    int error = 0;
    int lan = 0;

    string text;
    while (cin >> text)
    {
        auto words = split(text, "~");
        string ip = words[0];
        string mask = words[1];

        bool ipValid = true;
        words = split(ip, ".");
        vector<int> ipnums;
        if (words.size() == 4)
        {
            for (auto& i : words)
            {
                if (i.empty())
                {
                    ipValid = false;
                    break;
                }

                int n = stoi(i);
                if (n >= 0 && n <= 255)
                {
                    ipnums.push_back(n);
                }
                else
                {
                    ipValid = false;
                    break;
                }
            }
        }
        else
        {
            ipValid = false;
        }

        if (ipValid == false)
        {
            ++error;
            continue;
        }

        bool maskValid = true;
        words = split(mask, ".");
        vector<int> masknums;
        if (words.size() == 4)
        {
            for (auto& i : words)
            {
                if (i.empty())
                {
                    maskValid = false;
                    break;
                }

                int n = stoi(i);
                if (n >= 0 && n <= 255)
                {
                    masknums.push_back(n);
                }
                else
                {
                    maskValid = false;
                    break;
                }
            }
        }
        else
        {
            maskValid = false;
        }

        if (maskValid)
        {
            uint32_t maskn = 0;
            for (auto n : masknums)
            {
                maskn <<= 8;
                maskn += (uint32_t)n;
            }

            uint32_t base = 1;
            bool find0 = false;
            for (int i = 31; i >= 0; --i)
            {
                if ((base << i) & maskn)
                {
                    if (find0)
                    {
                        maskValid = false;
                        break;
                    }
                }
                else
                {
                    find0 = true;
                }
            }

            if (maskn == UINT32_MAX ||
                maskn == 0)
            {
                maskValid = false;
            }
        }

        if (maskValid == false)
        {
            ++error;
            continue;
        }

        if (ipnums[0] >= 1 && ipnums[0] <= 126)
        {
            ++A;
        }
        else if (ipnums[0] >= 128 && ipnums[0] <= 191)
        {
            ++B;
        }
        else if (ipnums[0] >= 192 && ipnums[0] <= 223)
        {
            ++C;
        }
        else if (ipnums[0] >= 224 && ipnums[0] <= 239)
        {
            ++D;
        }
        else if (ipnums[0] >= 240 && ipnums[0] <= 255)
        {
            ++E;
        }

        if (ipnums[0] == 10 ||
            (ipnums[0] == 172 && ipnums[1] >= 16 && ipnums[1] <= 31) ||
            (ipnums[0] == 192 && ipnums[1] == 168))
        {
            ++lan;
        }
    }

    cout << A << " " << B << " " << C << " " << D << " " << E << " " << error << " " << lan << endl;
    return 0;
}