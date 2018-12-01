#include "pch.h"
#include "BasicSort.h"

BasicSort::BasicSort()
{
}


BasicSort::~BasicSort()
{
}

void BasicSort::print_arr(std::vector <int> arr) //function for printing the array/vector
{
	for (unsigned int i = 0; i < arr.size(); i++) {
		printf("%d  ", arr[i]);
	}
}

void BasicSort::set_arr_elements() //function for getting the elements of the array/vector
{
	int temp = 0;
	for (int i = 0; i < arr_size; i++) {
		std::cin >> temp;
		object_arr.push_back(temp);
	}
}

void BasicSort::insertion()
{
	std::vector <int> insertion_arr;
	insertion_arr = object_arr;
	int i = 1, j = 0, step = 1;
	int temp = 0;
	while (i < (int)insertion_arr.size()) {
		j = i - 1;
		while (j >= 0 && insertion_arr[j + 1] < insertion_arr[j]) {
			// swapping
			temp = insertion_arr[j];
			insertion_arr[j] = insertion_arr[j + 1];
			insertion_arr[j + 1] = temp;
			j--;
		}
		printf("\nStep %d: ", step);
		print_arr(insertion_arr);
		step++;
		printf("\n");
		i++;
	}
	final_result(insertion_arr);
}

void BasicSort::selection()
{
	int temp = 0, step = 1;
	std::vector <int> selection_arr;
	selection_arr = object_arr;
	for (unsigned int i = 0; i < selection_arr.size() - 1; i++) {
		for (unsigned int j = i + 1; j < selection_arr.size(); j++) {
			if (selection_arr[i] > selection_arr[j]) {
				temp = selection_arr[i];
				selection_arr[i] = selection_arr[j];
				selection_arr[j] = temp;
			}
		}
		printf("\nStep %d: ", step);
		print_arr(selection_arr);
		printf("\n");
		step++;
	}
	final_result(selection_arr);
}

void BasicSort::bubble()
{
	int temp = 0, step = 1;
	std::vector <int> bubble_arr;
	bubble_arr = object_arr;
	for (unsigned int i = 0; i < bubble_arr.size() - 1; i++) {
		bool isSwapped = false;
		for (unsigned int j = 0; j < bubble_arr.size() - 1; j++) {
			if (bubble_arr[j] > bubble_arr[j + 1]) {
				temp = bubble_arr[j + 1];
				bubble_arr[j + 1] = bubble_arr[j];
				bubble_arr[j] = temp;
				isSwapped = true;
			}
		}
		if (!isSwapped) {
			break;
		}
		printf("\nStep %d: ", step);
		print_arr(bubble_arr);
		printf("\n");
		step++;
	}
	final_result(bubble_arr);
}

void BasicSort::final_result(std::vector <int> arr)
{
	printf("\n\nResult: \n\n");
	BasicSort::print_arr(arr);
}

void BasicSort::set_arr_size(int n)
{
	arr_size = n;
}

std::vector <int> BasicSort::get_arr_elements()
{
	return object_arr;
}

int BasicSort::get_arr_size()
{
	return arr_size;
}