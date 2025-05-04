// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 public:
void push(const T& element) {
Noda* newNoda = new Noda(element);
if (element.prior > head->data.prior || !head) {
            newNoda->next = head;
head = newNoda;
} else {
Noda* current = head;
while (current->next && current->next->data.prior >= element.prior) {
current = current->next;
}
newNoda->next = current->next;
current->next = newNoda;
}
}
T pop() {
if (!head)
throw std::out_of_range("Queue is empty!");
Noda* current = head;
T result = head->data;
head = head->next;
delete current;
return result;
}
TPQueue() : head(nullptr) {}
~TPQueue() {
while (head) {
Noda* current = head;
head = head->next;
delete current;
}
}
bool empty() const {
return head == nullptr;
}

 private:
struct Noda {
T data;
Noda* next;
explicit Noda(const T& _data) : data(_data), next(nullptr) {}
};
Noda* head;
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
