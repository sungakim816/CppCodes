#pragma once
#include <iostream>
#include <vector>

class BasicSort
{
public:
    BasicSort();
    ~BasicSort();
    void bubble();
    void selection();
    void insertion();
    void set_arr_elements();
    void set_arr_size(int n);
    std::vector<int> get_arr_elements();
    int get_arr_size();

private:
    int arr_size;
    std::vector<int> object_arr;
    void print_arr(std::vector<int> arr);
    void final_result(std::vector<int> arr);
};
