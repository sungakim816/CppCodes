// BasicSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// erase no more
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "pch.h"
#include "BasicSort.h"

int main()
{
	int arr_size = 0;
	std::vector <int> view_arr;
	std::vector <int>::iterator iter;
	BasicSort sort_demo;
	printf("\t\t\tBasic Sorting Algorithm.....\n\n\n");
	printf("Enter Number of terms(Should Be less than 100): ");
	std::cin >> arr_size;
	sort_demo.set_arr_size(arr_size);
	printf("\nEnter Elements separated by space: ");
	sort_demo.set_arr_elements();
	system("cls");
	view_arr = sort_demo.get_arr_elements();
	printf("\nElements To be Sorted: \n\n");
	for (iter = view_arr.begin(); iter != view_arr.end(); iter++) {
		printf("%d ", *iter);
	}
	printf("\n\nSimple Demonstration of Bubble Sort Algorithm...\n\n");
	sort_demo.bubble();
	printf("\n\nSimple Demonstration of Insertion Sort Algorithm...\n\n");
	sort_demo.insertion();
	printf("\n\nSimple Demonstration of Selection Sort Algorithm...\n\n");
	sort_demo.selection();
	printf("\n");
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

