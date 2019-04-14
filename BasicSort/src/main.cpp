// BasicSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "basicsort.h"

int main()
{
	int arr_size = 0;
	std::vector<int> view_arr;
	std::vector<int>::iterator iter;
	BasicSort sort_demo;
	std::cout << "\t\tBasic Sorting Algorithm.....\n\n"
			  << std::endl;
	std::cout << "Enter Number of terms(Should Be less than 100): " << std::endl;
	std::cin >> arr_size;
	sort_demo.set_arr_size(arr_size);
	std::cout << "\nEnter " << arr_size << " Elements separated by space: " << std::flush;
	sort_demo.set_arr_elements();
	std::cin.get();
	view_arr = sort_demo.get_arr_elements();
	std::cout << "Elements To be Sorted: " << std::flush;
	for (iter = view_arr.begin(); iter != view_arr.end(); iter++)
	{
		printf("%d ", *iter);
	}
	std::cout << "\n\nSimple Demonstration of Bubble Sort Algorithm..." << std::endl;
	sort_demo.bubble();
	std::cout << "\n\nSimple Demonstration of Insertion Sort Algorithm..." << std::endl;
	sort_demo.insertion();
	std::cout << "\n\nSimple Demonstration of Selection Sort Algorithm..." << std::endl;
	sort_demo.selection();
	printf("\n");
	std::cin.get();
	return 0;
}
