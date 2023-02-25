#include "roman_conversion.h"
#include "roman_math.h"

int addRoman(string romanNum1, string romanNum2)
{
    int num1 = romanToInt(romanNum1);
    int num2 = romanToInt(romanNum2);
    return num1 + num2;
}

int subRoman(string romanNum1, string romanNum2)
{
    int num1 = romanToInt(romanNum1);
    int num2 = romanToInt(romanNum2);
    return num1 - num2;
}