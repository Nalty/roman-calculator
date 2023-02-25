#include "roman_conversion.h"
#include <unordered_map>

string intToRoman(int num)
{
    string roman = "";
    unordered_map<int, string> numeral_map{
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };
    int divisors[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    int i = 0;
    while (num > 0) {
        if (num >= divisors[i]) {
            roman += numeral_map[divisors[i]];
            num -= divisors[i];
        }
        else i++;
    }
    return roman;
}

int romanToInt(string roman)
{
    int decimal = 0;
    unordered_map<char, int> numeral_map{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int prev = 0;
    int curr = 0;
    for (char c : roman) {
        c = toupper(c);
        curr = numeral_map[c];
        decimal += curr;
        if (curr > prev) {
            decimal -= 2 * prev;
        }
        prev = curr;
    }

    return decimal;
}

bool isValidRoman(const string& roman)
{
    unordered_map<char, int> numeral_map{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    char prev = ' ';
    int count = 0;

    for (char c : roman) {
        c = toupper(c);

        if (numeral_map.find(c) == numeral_map.end()) return false;

        if (prev == ' ') {
            prev = c;
            count = 1;
            continue;
        }

        if (numeral_map[c] > numeral_map[prev]) {
            if (count > 1) return false;
            if (prev != 'I' && prev != 'X' && prev != 'C') return false;

            prev = ' ';
            count = 0;
        }

        else if (numeral_map[c] == numeral_map[prev]) {
            if (c == 'V' || c == 'L' || c == 'D') return false;
            if (count == 3) return false;

            count++;
        }

        else {
            prev = c;
            count = 1;
        }
    }    
    return true;
}