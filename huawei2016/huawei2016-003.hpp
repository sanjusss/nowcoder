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

using namespace std;

int main()
{
    unordered_map<string, int> values;
    for (int i = 3; i <= 10; ++i)
    {
        values[to_string(i)] = i;
    }

    values["J"] = 11;
    values["Q"] = 12;
    values["K"] = 13;
    values["A"] = 14;
    values["2"] = 15;
    values["joker"] = 16;
    values["JOKER"] = 17;

    vector<string> input;
    vector<string> head1;
    vector<string> head2;

    string card;
    while (cin >> card)
    {
        int split = card.find_first_of('-');
        if (split >= 0)
        {
            input.push_back(card.substr(0, split));
            input.swap(head1);
            input.push_back(card.substr(split + 1));
        }
        else
        {
            input.push_back(card);
        }
    }

    input.swap(head2);

    vector<string> output;
    if (head1.size() == head2.size())
    {
        output.swap(values[head1[0]] > values[head2[0]] ? head1 : head2);
    }
    else
    {
        if (head1.size() > head2.size())
        {
            head1.swap(head2);
        }

        if (head1.size() == 2 && values[head1[0]] >= 16)
        {
            output.swap(head1);
        }
        else if (head1.size() == 4)
        {
            output.swap(head1);
        }
        else if (head2.size() == 4)
        {
            output.swap(head2);
        }
        else
        {
            output.push_back("ERROR");
        }
    }

    for (int i = 0; i < output.size(); ++i)
    {
        if (i != 0)
        {
            cout << " ";
        }

        cout << output[i];
    }

    cout << endl;
    return 0;
}