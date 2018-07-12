#include <stdio.h>
#include <unistd.h>
 
int main(void) {
    int microsecond = 0.997 * 1000000;
 
    printf("%dμ秒間止まります。\n", microsecond);
 
    usleep(microsecond);
 
    printf("%dμ秒間止まりました。\n", microsecond);
 
    return 0;
}