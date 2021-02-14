#include <iostream>
#include "LinkedList.hpp"

int main(int argc, char *argv[])
{
	LinkedList *linkedList = new LinkedList();
	// enter elements
	linkedList->push(1);
	linkedList->push(4);
	linkedList->push(3);
	linkedList->push(5);

	linkedList->print_all();

	linkedList->reverse();

	linkedList->print_all();
}