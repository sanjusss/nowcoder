#pragma once
#include "newcoder.h"

int main()
{
    string fileName;
    int lineNo;

    unordered_map<string, int> q;
    unordered_map<string, int> times;
    unordered_map<string, pair<string, int>> info;
    while (cin >> fileName >> lineNo)
    {
        fileName = fileName.substr(fileName.find_last_of('\\') + 1);
        string key = fileName + " " + to_string(lineNo);
        if (times.find(key) == times.end())
        {
            q[key] = q.size();
            if (fileName.size() > 16)
            {
                fileName = fileName.substr(fileName.size() - 16);
            }

            info[key] = { fileName, lineNo };
        }

        ++times[key];
    }

    map<int, map<int, string>> keys;
    for (auto i = times.begin(); i != times.end(); ++i)
    {
        keys[i->second][q[i->first]] = i->first;
    }

    int j = 0;
    for (auto i = keys.rbegin();
        i != keys.rend() && j < 8; ++i)
    {
        for (auto& k : i->second)
        {
            string& key = k.second;
            auto& p = info[key];
            cout << p.first << " " << p.second << " " << i->first << endl;

            if (++j == 8)
            {
                break;
            }
        }
    }

    return 0;
}