#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

#include <string>
#include <vector>

// Структура для представления одной костяшки
struct Domino {
    int left;
    int right;

    // Возвращает перевернутую костяшку
    Domino Reverse() const;
};

// Узел двухсвязного списка
struct Node {
    Domino data;
    Node* next;
    Node* prev;
    Node(Domino val);
};

// Реализация двухсвязного списка
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void PushBack(Domino val);
    void PopBack();
    void PushFront(Domino val);
    void PopFront();

    bool IsEmpty() const;
    Node* GetHead() const;
    Node* GetTail() const;

    void Print() const;
    void Clear();

private:
    Node* head_;
    Node* tail_;
};


#endif  // DOUBLY_LINKED_LIST_H_