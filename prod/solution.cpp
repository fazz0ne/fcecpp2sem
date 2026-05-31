#include "solution.h"

#include <iostream>
#include <stdexcept>

// Логика поиска решения
bool Solution::FindChain(std::vector<Domino>& unused, DoublyLinkedList& chain) {
    if (unused.empty()) {
        return true;
    }

    for (int i = 0; i < unused.size(); i++) {
        Domino d = unused[i];
        std::vector<Domino> next_unused = unused;
        next_unused.erase(next_unused.begin() + i);

        // Попытка прикрепить в конец
        if (chain.GetTail()->data.right == d.left) {
            chain.PushBack(d);
            if (FindChain(next_unused, chain)) return true;
            chain.PopBack();
        } else if (chain.GetTail()->data.right == d.right) {
            chain.PushBack(d.Reverse());
            if (FindChain(next_unused, chain)) return true;
            chain.PopBack();
        }

        // Попытка прикрепить в начало
        if (chain.GetHead()->data.left == d.right) {
            chain.PushFront(d);
            if (FindChain(next_unused, chain)) return true;
            chain.PopFront();
        } else if (chain.GetHead()->data.left == d.left) {
            chain.PushFront(d.Reverse());
            if (FindChain(next_unused, chain)) return true;
            chain.PopFront();
        }
    }

    return false;
}

void Solution::SolveDominoes(const std::vector<std::string>& input) {
    std::vector<Domino> unused;

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (!std::isdigit(input[i][j])) {
                throw std::invalid_argument("Не цифра в костяшке" + input[i]);
            }
        }
        if (input[i].length() != 2) {
            throw std::invalid_argument("Костяшка " + input[i] + " должна состоять из двух цифр");
        }
        unused.push_back({std::stoi(std::string(1, input[i][0])), std::stoi(std::string(1, input[i][1]))});
    }

    DoublyLinkedList chain;
    Domino anchor = unused[0];
    unused.erase(unused.begin());

    //исходное домино
    chain.PushBack(anchor);
    if (FindChain(unused, chain)) {
        std::cout << "можно: ";
        chain.Print();
        return;
    }
    chain.PopBack();

    //перевернутое
    if (anchor.left != anchor.right) {
        chain.PushBack(anchor.Reverse());
        if (FindChain(unused, chain)) {
            std::cout << "можно: ";
            chain.Print();
            return;
        }
        chain.PopBack();
    }
}