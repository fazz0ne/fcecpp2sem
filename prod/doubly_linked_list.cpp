#include "doubly_linked_list.h"

#include <iostream>
#include <string>
#include <vector>

// Методы Domino
Domino Domino::Reverse() const {
  return {right, left};
}

// Конструктор Node
Node::Node(Domino val) : data(val), next(nullptr), prev(nullptr) {}

// Методы DoublyLinkedList
DoublyLinkedList::DoublyLinkedList() : head_(nullptr), tail_(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
  Clear();
}

void DoublyLinkedList::PushBack(Domino val) {
  Node* new_node = new Node(val);
  if (!head_) {
    head_ = tail_ = new_node;
  } else {
    tail_->next = new_node;
    new_node->prev = tail_;
    tail_ = new_node;
  }
}

void DoublyLinkedList::PopBack() {
  if (!tail_) return;
  Node* temp = tail_;
  if (head_ == tail_) {
    head_ = tail_ = nullptr;
  } else {
    tail_ = tail_->prev;
    tail_->next = nullptr;
  }
  delete temp;
}

void DoublyLinkedList::PushFront(Domino val) {
  Node* new_node = new Node(val);
  if (!head_) {
    head_ = tail_ = new_node;
  } else {
    new_node->next = head_;
    head_->prev = new_node;
    head_ = new_node;
  }
}

void DoublyLinkedList::PopFront() {
  if (!head_) return;
  Node* temp = head_;
  if (head_ == tail_) {
    head_ = tail_ = nullptr;
  } else {
    head_ = head_->next;
    head_->prev = nullptr;
  }
  delete temp;
}

bool DoublyLinkedList::IsEmpty() const { return head_ == nullptr; }
Node* DoublyLinkedList::GetHead() const { return head_; }
Node* DoublyLinkedList::GetTail() const { return tail_; }

void DoublyLinkedList::Print() const {
  Node* current = head_;
  while (current) {
    std::cout << current->data.left << current->data.right;
    if (current->next) std::cout << ", ";
    current = current->next;
  }
  std::cout << std::endl;
}

void DoublyLinkedList::Clear() {
  while (!IsEmpty()) {
    PopBack();
  }
}