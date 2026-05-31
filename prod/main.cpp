#include <iostream>

#include "correct_number.h"
#include "solution.h"

int main() {
    std::vector<std::string> input = {"134"};
    int choice;
    do {
        std::cout << "1. Добавить костяшку\n"
                     "2. Удалить костяшку\n"
                     "3. Изменить костяшку\n"
                     "4. Загрузить из файла\n"
                     "5. Проверить, можно ли выложить в ряд\n"
                     "Выбор: ";
        CorrectNumber::FineNum(choice);
        switch (choice) {
            case 1: {
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                break;
            }
            case 5: {
                try {
                    Solution::SolveDominoes(input);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
        }
    } while (choice!=0);

    return 0;
}
