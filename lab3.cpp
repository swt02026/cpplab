#include <cstring>
#include <cstdio>

int main()
{
    char buf[100] = {0};

    int flag = 0;
    
    memset(buf, 'a', 1000);
// b 12
// p &flag
// p &buf
// p $rbp 
// valid $rbp stack frame 
// check (&flag - &buf) <= 1000


// or g++  -fsanitize=address -g lab3.cpp
    if(flag)
    {
        printf("into if stmt\n");
    }
}