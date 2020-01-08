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

//分割字符串
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
	vector<string> names = { "HKD", "CNY", "USD", "GBP" };
	string line;
	while (getline(cin, line))
	{
		vector<string> text = split(line, " ");
		if (text.size() != 6)
		{
			cout << "ERROR" << endl;
			continue;
		}
		
		bool valid = true;
		vector<int> nums(4, 0);
		for (int i = 0; i < 4 && valid; ++i)
		{
			if (text[i].empty())
			{
				valid = false;
				break;
			}

			for (auto c : text[i])
			{
				if (isdigit(c))
				{
					nums[i] = nums[i] * 10 + (c - '0');
				}
				else
				{
					valid = false;
					break;
				}
			}

			if (nums[i] == 0)
			{
				valid = false;
			}
		}

		int type = -1;
		for (int i = 0; i < 4; ++i)
		{
			if (text[4] == names[i])
			{
				type = i;
				break;
			}
		}

		if (type == -1)
		{
			valid = false;
		}

		bool isMax = text[5] == "MAX";
		if (text[5] != "MAX" && text[5] != "MIN")
		{
			valid = false;
		}

		string output;
		if (valid)
		{
			if (isMax)
			{
				int n = nums[3];
				for (int i = type; i < 3; ++i)
				{
					int r = n % nums[i];
					n /= nums[i];
					if (r > 0)
					{
						output = to_string(r) + " " + names[i] + " " + output;
					}
				}

				if (n > 0)
				{
					output = to_string(n) + " GBP " + output;
				}

				output.erase(output.size() - 1);
			}
			else
			{
				int hkd = nums[3];
				for (int i = type - 1; i >= 0; --i)
				{
					hkd *= nums[i];
				}

				output = to_string(hkd) + " HKD";
			}
		}
		else
		{
			output = "ERROR";
		}

		cout << output << endl;
	}

    return 0;
}