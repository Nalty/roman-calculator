#include <iostream>
#include "roman_conversion.h"
#include "roman_math.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int mode;
    do {
        cout << "�������� ����� ������ (����� ��������� ������, ������� 0)." << endl;
        cout << "1. �������������� ����������� ����� � �������" << endl;
        cout << "2. �������������� �������� ����� � ����������" << endl;
        cout << "3. �������� / ��������� ������� �����\n";
        cin >> mode;

        if (mode == 1) {
            int num;
            string roman;

            do {
                cout << "������� ���������� ����� �� ��������� �� 1 �� 3999: ";
                cin >> num;
            } while (num < 1 || num > 3999);

            roman = intToRoman(num);
            cout << "������� ����������� ����� " << num << " � ������� ������� ��������� �������� ����� " << roman << ".\n\n";
        }

        else if (mode == 2) {
            string roman;
            int num;
            do {
                cout << "������� ������� ����� �� ��������� �� I �� MMMCMXCIX: ";
                cin >> roman;
            } while (!isValidRoman(roman));

            num = romanToInt(roman);
            cout << "������� �������� ����� " << roman << " � ���������� ������� ��������� �������� ����� " << num << ".\n\n";
        }

        else if (mode == 3) {
            string romanNum1, romanNum2;
            string resultRoman;
            int resultNum;
            char operation;

            do {
                cout << "������� ������ ������� �����: ";
                cin >> romanNum1;
            } while (!isValidRoman(romanNum1));

            do {
                cout << "�������� �������� (+ ��� -): ";
                cin >> operation;
            } while (operation != '+' && operation != '-');

            do {
                cout << "������� ������ ������� �����: ";
                cin >> romanNum2;
            } while (!isValidRoman(romanNum2));

            if (operation == '+') resultNum = addRoman(romanNum1, romanNum2);
            else resultNum = subRoman(romanNum1, romanNum2);

            resultRoman = intToRoman(resultNum);

            if (isValidRoman(resultRoman)) {
                cout << "���� ����������� ��������� �������� '" << romanNum1 << " " << operation << " " << romanNum2 << "'." << endl;
                cout << "��������� � ���������� ������� ���������: " << resultNum << endl;
                cout << "��������� � ������� ������� ���������: " << resultRoman << "\n\n";
            }
            else {
                cout << "����������� �������������� �������� '" << romanNum1 << " " << operation << " " << romanNum2 << "' �������� ������������ ������� �����.\n";
                cout << "����������, ���������� �����.\n\n";
            }
        }
    } while (mode != 0);

    return 0;
}