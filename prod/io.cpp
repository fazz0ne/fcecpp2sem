#include "io.h"
#include "correct_domino.h"
#include "correct_number.h"

#include <iostream>
#include <fstream>

void IO::Input(std::vector<std::string> &in) {
    std::string data;
    std::cout << "Введите значение: ";
    std::cin >> data;
    try {
        CorrectDomino::Check(data);
        in.push_back(data);
        std::cout << "Добавлено " << data << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

void IO::Output(std::vector<std::string> &out) {
    if (out.empty()) {
        std::cout << "Не введены данные\n";
        return;
    }
    std::cout << "Действующий набор" << std::endl;
    for (int i = 0; i < out.size(); i++) {
        if (i != out.size() - 1) {
            std::cout << out[i] << " ";
        }
        else {
            std::cout << out[i] << std::endl;
        }
    }
}

void IO::ToDelete(std::vector<std::string> &d) {
    if (d.empty()) {
        std::cout << "Не введены данные\n";
        return;
    }
    int number_to_delete;
    std::cout << "Введите номер: ";
    CorrectNumber::FineNumFrames(number_to_delete,1, d.size());
    std::cout << "Удалено " << d[number_to_delete-1] << std::endl;
    d.erase(d.begin() + number_to_delete - 1);
}

void IO::Change(std::vector<std::string> &d) {
    if (d.empty()) {
        std::cout << "Не введены данные\n";
        return;
    }
    int number_to_change;
    std::string new_value;
    std::cout << "Введите номер: ";
    CorrectNumber::FineNumFrames(number_to_change,1, d.size());
    std::cout << "Введите новое значение";
    try {
        CorrectDomino::Check(new_value);
        std::cout << d[number_to_change-1] << "Изменен на " << new_value << std::endl;
        d[number_to_change-1] = new_value;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
}

void IO::InputFromFile(std::vector<std::string> &in) {
    std::ifstream file("data.txt");

    if (!file.is_open()) {
        std::cout << "Ошибка: Не удалось открыть файл 'data.txt'. Проверьте, существует ли он в папке с программой.\n";
    } else {
        std::string piece;
        while (file >> piece) {
            in.push_back(piece);
        }
        std::cout << "Успешно загружено\n";
        file.close();
    }

    for (int i = 0; i < in.size();) {
        try {
            CorrectDomino::Check(in[i]);
            i++;
        }
        catch (const std::invalid_argument& e) {
            std::cout << in[i] << " Удалён: " << e.what() << std::endl;
            in.erase(in.begin() + i);
        }
    }
}