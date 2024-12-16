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
// check = Invalid free() / delete / delete[] / realloc()


// or g++  -fsanitize=address -g lab5.cpp
int main()
{

    auto i = get_a_address();
    free_a_address(i);
    free_a_address(i);

}

