#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static inline int get_fs(void)
{
    int _v;
    __asm__ ("movec %/dfc,%0":"=r" (_v):);
    return _v;
}

void test_asm()
{
    printf("====== asm test begin ============\n");
//    get_fs();




    printf("====== asm test end   ============\n");


}

// int main(int argc, char **argv)
// {

    // test_asm();

    // return 0;
	
// }


