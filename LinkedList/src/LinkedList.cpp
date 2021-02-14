#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList()
{
    this->head = nullptr;
}

// insert new entry at the beginning of the list
void LinkedList::push(int data)
{
    Node *node = new Node();
    node->value = data;
    node->next = this->head;
    this->head = node;
}

Node *LinkedList::get_head()
{
    return this->head;
}

void LinkedList::print_all()
{
    Node *curr = this->head;
    while (curr)
    {
        std::cout << curr->value << " " << std::flush;
        curr = curr->next;
    }
    std::cout << std::endl;
}

void LinkedList::reverse()
{
    Node *curr_head = this->head;
    Node *next = nullptr;

    while (curr_head)
    {
        // get the current next pointer
        Node *curr_next = curr_head->next;
        // set current head next pointer to new
        curr_head->next = next;
        // set new next to the current head
        next = curr_head;
        // set current head to current next
        curr_head = curr_next;
        // set head's next to new next
        if (curr_head)
        {
            this->head = curr_head;
        }
    }
}