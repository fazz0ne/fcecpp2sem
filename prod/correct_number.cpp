#include "correct_number.h"

#include <iostream>
#include <limits>

void CorrectNumber::FineNum(int& num) {
    bool flag = false;
    do {
        if (!(std::cin >> num)) {
            std::cout << "Введите корректное значение: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            flag = true;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!flag);
}

void CorrectNumber::FineNumN(int& num) {
    bool flag = false;
    do {
        FineNum(num);
        if (num <= 0) {
            std::cout << "Введите значение >0: ";
        } else {
            flag = true;
        }
    } while (!flag);
}

void CorrectNumber::FineNumDouble(double& num) {
    bool flag = false;
    do {
        if (!(std::cin >> num)) {
            std::cout << "Введите корректное значение: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            flag = true;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!flag);
}

void CorrectNumber::FineNumPositive(int& num) {
    bool flag = false;
    do {
        FineNum(num);
        if (num < 0) {
            std::cout << "Введите значение >=0: ";
        } else {
            flag = true;
        }
    } while (!flag);
}

void CorrectNumber::FineNumFrames(int& num, int f1, int f2) {
    bool flag = false;
    do {
        FineNum(num);
        if ((num < f1) || (num > f2)) {
            std::cout << "Введите значение >=" << f1 << "=<" << f2 << "\n";
        } else {
            flag = true;
        }
    } while (!flag);
}