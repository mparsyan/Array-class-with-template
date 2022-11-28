#include <iostream>
#include "include/arr_class_temp.h"

int main()
{
    Array<int> arr1(2);
    arr1[0] = 12;
    arr1[1] = 42;
    Array<int> arr2(3);
    arr1 = arr2;
    std::cout << (arr1 == arr2) << '\n';
    std::cout << arr2.size() << '\n';
}