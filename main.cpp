#include <iostream>
#include "roman_conversion.h"
#include "roman_math.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int mode;
    do {
        cout << "Выберите режим работы (чтобы завершить работу, введите 0)." << endl;
        cout << "1. Преобразование десятичного числа в римское" << endl;
        cout << "2. Преобразование римского числа в десятичное" << endl;
        cout << "3. Сложение / вычитание римских чисел\n";
        cin >> mode;

        if (mode == 1) {
            int num;
            string roman;

            do {
                cout << "Введите десятичное число из диапазона от 1 до 3999: ";
                cin >> num;
            } while (num < 1 || num > 3999);

            roman = intToRoman(num);
            cout << "Записью десятичного числа " << num << " в римской системе счисления является число " << roman << ".\n\n";
        }

        else if (mode == 2) {
            string roman;
            int num;
            do {
                cout << "Введите римское число из диапазона от I до MMMCMXCIX: ";
                cin >> roman;
            } while (!isValidRoman(roman));

            num = romanToInt(roman);
            cout << "Записью римского числа " << roman << " в десятичной системе счисления является число " << num << ".\n\n";
        }

        else if (mode == 3) {
            string romanNum1, romanNum2;
            string resultRoman;
            int resultNum;
            char operation;

            do {
                cout << "Введите первое римское число: ";
                cin >> romanNum1;
            } while (!isValidRoman(romanNum1));

            do {
                cout << "Выберите операцию (+ или -): ";
                cin >> operation;
            } while (operation != '+' && operation != '-');

            do {
                cout << "Введите второе римское число: ";
                cin >> romanNum2;
            } while (!isValidRoman(romanNum2));

            if (operation == '+') resultNum = addRoman(romanNum1, romanNum2);
            else resultNum = subRoman(romanNum1, romanNum2);

            resultRoman = intToRoman(resultNum);

            if (isValidRoman(resultRoman)) {
                cout << "Ниже представлен результат операции '" << romanNum1 << " " << operation << " " << romanNum2 << "'." << endl;
                cout << "Результат в десятичной системе счисления: " << resultNum << endl;
                cout << "Результат в римской системе счисления: " << resultRoman << "\n\n";
            }
            else {
                cout << "Результатом арифметической операции '" << romanNum1 << " " << operation << " " << romanNum2 << "' является недопустимое римское число.\n";
                cout << "Пожалуйста, попробуйте снова.\n\n";
            }
        }
    } while (mode != 0);

    return 0;
}