#include <cstdio>
void ff()
{
    char buf[100];
    buf[0] = 'd';

}


// b 15
// p buf
void ee()
{
    char buf[100];
    if(buf[0] == 'd')
    {
        printf("into ee if stmt");
    }
}

int main()
{
    ff();
    ee();


}

