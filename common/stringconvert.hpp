#pragma once
#include <string>
#include <vector>

//·Ö¸î×Ö·û´®
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

//Ìæ»»×Ö·û´®ÖÐµÄ¶ÔÓ¦×Ö·û
std::string replaceAllString(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }

    return str;
}