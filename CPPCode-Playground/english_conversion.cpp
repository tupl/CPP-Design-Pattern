#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

std::vector<std::string> digits =
{
    "zero",
    "one", "two", "three",
    "four", "five", "six",
    "seven", "eight", "nine"
};

std::string chunk(int num) {
    std::string tmp;
    if (num >= 100) {
        int digit = num / 100;
        num %= 100;
        tmp += digits[digit] + " hundred ";
    }
    if (num >= 20) {

    } else
}
