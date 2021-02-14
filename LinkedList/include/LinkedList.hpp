#ifndef LinkedList_hpp
#define LinkeList_hpp

struct Node
{
    int value = 0;
    Node *next = nullptr;
};

class LinkedList
{
public:
    LinkedList();
    void push(int data);
    void reverse();
    void print_all();
    Node *get_head();

private:
    Node *head;
};

#endif