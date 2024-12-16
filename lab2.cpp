#include <cstring>
#include <cstdio>

int main()
{
    char buf[100] = {0};

    int flag = 0;
    
    memset(buf, 'a', 120);
// b 12
// p &flag
// p &buf

// check (&flag - &buf) <= 120


// or g++  -fsanitize=address -g lab2.cpp
    if(flag)
    {
        printf("into if stmt\n");
    }
}