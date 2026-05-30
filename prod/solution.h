
#ifndef PROD_SOLUTION_H
#define PROD_SOLUTION_H
#include "doubly_linked_list.h"


class Solution {
public:
    bool static FindChain(std::vector<Domino>& unused, DoublyLinkedList& chain);
    void static SolveDominoes(const std::vector<std::string>& input);
};


#endif //PROD_SOLUTION_H