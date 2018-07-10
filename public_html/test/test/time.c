#include <stdio.h>
#include <time.h>
// 出力例：2011.08.31 20:35:50
int main() {
    time_t timer = time(NULL);
    struct tm *date = localtime(&timer); 
    printf("%d.%02d.%02d %2d:%02d:%02d", 
	date->tm_year+1900, date->tm_mon+1, date->tm_mday, 
	date->tm_hour, date->tm_min, date->tm_sec);
}