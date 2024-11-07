#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
std::string Transform_(const std::string &words)
{
    std::vector<char> words_t;
    std::transform(words.begin(), words.end(), std::back_inserter(words_t),toupper);
    std::string Soundex_code;
    auto judge = [](const char &x) -> char
    {
        if (x == 'B' || x == 'F' || x == 'P' || x == 'V')
        {
            return '1';
        }
        else if (x == 'C' || x == 'G' || x == 'J' || x == 'K' || x == 'Q' || x == 'S' || x == 'X' || x == 'Z')
        {
            return '2';
        }
        else if (x == 'D' || x == 'T')
        {
            return '3';
        }
        else if (x == 'L')
        {
            return '4';
        }
        else if (x == 'M' || x == 'N')
        {
            return '5';
        }
        else if (x == 'R')
        {
            return '6';
        }
        else
        {
            return '0';
        }
    };
    Soundex_code += words_t[0];

    for (auto it = words_t.begin() + 1; it != words_t.end(); ++it)
    {
        char soundex_char = judge(*it);

        if (soundex_char != Soundex_code.back() and soundex_char != '0')
        {
            //和前一个不一样并且不为0在加入
            Soundex_code += soundex_char;
        }
    }
    Soundex_code.resize(4, '0');
    //不足4位补0
    return Soundex_code;
}

int main()
{
    std::string original_code;
    std::cin >> original_code;
    std::cout << Transform_(original_code);
    return 0;
}