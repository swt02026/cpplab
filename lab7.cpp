#include <cstdio>
#include <unistd.h>
#include <cstring>
int main()
{

    FILE* fp = fopen(
        "test.txt",
        "r"
    );
    char buf[100];



    while(true)
    {
        fread(buf, sizeof(buf), sizeof(buf[0]), fp);

        // ltrace ./a.out
        // check strncmp or memcmp
        if(strncmp(buf, "aaaa", 4) == 0)
        {
            break;
        }
        sleep(1);
    }
}