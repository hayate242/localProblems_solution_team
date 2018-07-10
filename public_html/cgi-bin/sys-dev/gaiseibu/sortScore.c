#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <cgi.h>
//content-type: text/html

/*
* sortScore 使い方
*	sortScore(名前（Char型配列）,　スコア(int型), 日付(char型配列));
*　戻り値はスコアに対して降順にソートされた配列です
*/

int sortScore( char* name, int* score,char* date ){

	int i;
	int ret;



	return 1;
}

int main(void)
{
	printf( "content-type: text/html\n\n");
	//printf(HTML_HEADER("UTF-8")); /* Web ページの文字コードは UTF-8 が一般的 */
  printf("<html>\n<body>\n");

	char name[256];
	int score[256];
	int date[3]; // date[0] = year date[1] = month date[2] = day

	sortScore(name,score,date);
	if(fwresult){
		printf("File write Success\n");
	}else {

	}	

 printf( "こんにちは世界\n</body>\n</html>\n");
	

	return 0;
}

