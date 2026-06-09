#include "correct_number.h"
#include "io.h"
#include "solution.h"

#include <iostream>

int main() {
    std::vector<std::string> data;
    int choice;
    do {
        std::cout << "1. Добавить костяшку\n"
                     "2. Удалить костяшку\n"
                     "3. Изменить костяшку\n"
                     "4. Загрузить из файла data.txt\n"
                     "5. Вывести костяшки\n"
                     "6. Проверить, можно ли выложить в ряд\n"
                     "0. Выход\n"
                     "Выбор: ";
        CorrectNumber::FineNum(choice);
        switch (choice) {
            case 1: {
                IO::Input(data);
                break;
            }
            case 2: {
                IO::Output(data);
                IO::ToDelete(data);
                break;
            }
            case 3: {
                IO::Output(data);
                IO::Change(data);
                break;
            }
            case 4: {
                IO::InputFromFile(data);
                break;
            }
            case 5: {
                IO::Output(data);
                break;
            }
            case 6: {
                try {
                    if (data.empty())
                        std::cout << "Данные не введены\n";
                    else {
                        Solution::SolveDominoes(data);
                    }
                }
                catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 0: {
                std::cout << "Выход\n";
                break;
            }
            default: {
                std::cout << "Пункт отсутствует\n";
            }
        }
    } while (choice!=0);

    return 0;
}
