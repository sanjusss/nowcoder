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
��ǿ����ܿ��ģ���˾����NԪ�����ս�����ǿ���������ս����ڹ�������������Ʒ��Ϊ���ࣺ�����븽���������Ǵ�����ĳ�������ģ��±����һЩ�����븽�������ӣ�
����	����
����	��ӡ����ɨ����
���	ͼ��
����	̨�ƣ��ľ�
������	��
���Ҫ�����Ϊ��������Ʒ����������ø���������������ÿ������������ 0 ���� 1 ���� 2 �����������������д������Լ��ĸ�����
��ǿ����Ķ����ܶ࣬Ϊ�˲�����Ԥ�㣬����ÿ����Ʒ�涨��һ����Ҫ�ȣ���Ϊ 5 �ȣ�
������ 1 ~ 5 ��ʾ���� 5 ������Ҫ���������������ϲ鵽��ÿ����Ʒ�ļ۸񣨶��� 10 Ԫ��������������ϣ���ڲ����� N Ԫ�����Ե��� N Ԫ����ǰ���£�ʹÿ����Ʒ�ļ۸�����Ҫ�ȵĳ˻����ܺ����
    ��� j ����Ʒ�ļ۸�Ϊ v[j] ����Ҫ��Ϊ w[j] ����ѡ���� k ����Ʒ���������Ϊ j 1 �� j 2 �������� j k ����������ܺ�Ϊ��
v[j 1 ]*w[j 1 ]+v[j 2 ]*w[j 2 ]+ �� +v[j k ]*w[j k ] �������� * Ϊ�˺ţ�
    ���������ǿ���һ������Ҫ��Ĺ��ﵥ��
��������:
����ĵ� 1 �У�Ϊ��������������һ���ո������N m
������ N �� <32000 ����ʾ��Ǯ���� m �� <60 ��Ϊϣ��������Ʒ�ĸ�������
�ӵ� 2 �е��� m+1 �У��� j �и����˱��Ϊ j-1 ����Ʒ�Ļ������ݣ�ÿ���� 3 ���Ǹ����� v p q
������ v ��ʾ����Ʒ�ļ۸� v<10000 ���� p ��ʾ����Ʒ����Ҫ�ȣ� 1 ~ 5 ���� q ��ʾ����Ʒ���������Ǹ�������� q=0 ����ʾ����ƷΪ��������� q>0 ����ʾ����ƷΪ������ q �����������ı�ţ�

�������:
 ����ļ�ֻ��һ����������Ϊ��������Ǯ������Ʒ�ļ۸�����Ҫ�ȳ˻����ܺ͵����ֵ�� <200000 ����

ʾ��1
����
1000 5 800 2 0 400 5 1 300 5 1 400 3 0 500 2 0
���
2200
*/

//��Ʒ��Ŵ�1��ʼ
struct Item
{
    int index;
    int price;
    int weight;
    int parent;
    int pw;
};

int main()
{
    int maxMoney;
    int itemCount;
    while (cin >> maxMoney >> itemCount)
    {
        vector<Item> items(itemCount + 1);
        for (int i = 1; i <= itemCount; ++i)
        {
            auto& item = items[i];
            item.index = i;
            cin >> item.price >> item.weight >> item.parent;
            item.pw = item.price * item.weight;
        }


    }

    return 0;
}