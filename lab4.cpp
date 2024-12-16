#include <iostream>

int* get_a_address()
{
    return new int;
}


void free_a_address(int *& addr)
{
    delete addr;
}

// valgrind ./a.out
// check LEAK SUMMARY


// // or g++  -fsanitize=address -g lab4.cpp
int main()
{

    auto i = get_a_address();
    //free_a_address(i);

}

