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
https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68?tpId=37&tqId=21250&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
*/

int main()
{
    int count;
    while (cin >> count)
    {
        unordered_map<string, multiset<string>> dics;
        for (int i = 0; i < count; ++i)
        {
            string word;
            cin >> word;
            string key = word;
            sort(key.begin(), key.end());
            dics[key].insert(word);
        }

        string search;
        cin >> search;
        string searchKey = search;
        sort(searchKey.begin(), searchKey.end());
        cout << dics[searchKey].size() - dics[searchKey].count(search) << endl;

        int index;
        cin >> index;
        for (auto i = dics[searchKey].begin(); i != dics[searchKey].end(); ++i)
        {
            if (*i == search)
            {
                continue;
            }

            if (--index == 0)
            {
                cout << *i << endl;
                break;
            }
        }
    }

    return 0;
}