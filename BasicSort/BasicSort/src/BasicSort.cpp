#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// erase no more
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "BasicSort.h"

BasicSort::BasicSort()
{
    //ctor
}

BasicSort::~BasicSort()
{
    //dtor
}

void BasicSort::print_arr(std::vector <int> arr) //function for printing the array/vector
{
for (unsigned int i = 0; i < arr.size(); i++){
    printf("%d  ", arr[i]);
    }
}

void BasicSort::set_arr_elements() //function for getting the elements of the array/vector
{
int temp = 0;
for (int i = 0; i < arr_size; i++){
    scanf("%d", &temp);
    object_arr.push_back(temp);
    }
}

void BasicSort::insertion()
{
int temp = 0, step = 1;
std::vector <int> insertion_arr;
insertion_arr = object_arr;
for (unsigned int i = 1; i < insertion_arr.size(); i++){
    for (int j = i; j > 0; j--){
        if (insertion_arr[j] < insertion_arr[j-1]){
            temp = insertion_arr[j];
            insertion_arr[j] = insertion_arr[j-1];
            insertion_arr[j-1] = temp;
        }
    }
        printf("\nStep %d: ", step);
        print_arr(insertion_arr);
        step++;
        printf("\n");
    }
    final_result(insertion_arr);
}

void BasicSort::selection()
{
int temp = 0, step = 1;
std::vector <int> selection_arr;
selection_arr = object_arr;
for (unsigned int i = 0; i < selection_arr.size() - 1; i++){
    for (unsigned int j = i + 1; j < selection_arr.size(); j++){
        if (selection_arr[i] > selection_arr[j]){
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
for(unsigned int i = 0; i < bubble_arr.size() - 1; i++){
    for (unsigned int j = 0; j < bubble_arr.size() - 1; j++){
        if (bubble_arr[j] > bubble_arr[j+1]){
            temp = bubble_arr[j+1];
            bubble_arr[j+1] = bubble_arr[j];
            bubble_arr[j] = temp;
            }
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
