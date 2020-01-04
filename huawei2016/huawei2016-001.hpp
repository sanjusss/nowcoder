#pragma once
#include "newcoder.h"

int main()
{
    int studentCount;
    int opCount;
    while (cin >> studentCount >> opCount)
    {
        vector<int> scores(studentCount + 1, 0);
        for (int i = 1; i <= studentCount; ++i)
        {
            cin >> scores[i];
        }

        for (int i = 0; i < opCount; ++i)
        {
            char op;
            cin >> op;
            if (op == 'Q')
            {
                int start;
                int end;
                cin >> start >> end;
                if (start > end)
                {
                    swap(start, end);
                }

                cout << (*max_element(next(scores.begin(), start), next(scores.begin(), end + 1))) << endl;
            }
            else if (op == 'U')
            {
                int id;
                int score;
                cin >> id >> score;
                scores[id] = score;
            }
        }
    }

    return 0;
}