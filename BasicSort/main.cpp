#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// erase no more
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "BasicSort.h"

int main()
{   int arr_size = 0;
    std::vector <int> view_arr;
    std::vector <int>::iterator iter;
    BasicSort sort_demo;
    printf("\t\t\tBasic Sorting Algorithm.....\n\n\n");
    printf("Enter Number of terms(Should Be less than 100): ");
    scanf("%d", &arr_size);
    sort_demo.set_arr_size(arr_size);
    printf("\nEnter Elements separated by space: ");
    sort_demo.set_arr_elements();
    system("cls");
    view_arr = sort_demo.get_arr_elements();
    printf("\nElements To be Sorted: \n\n");
    for(iter = view_arr.begin(); iter != view_arr.end(); iter++){
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
