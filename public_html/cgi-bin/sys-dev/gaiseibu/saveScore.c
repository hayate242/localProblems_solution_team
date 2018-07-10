#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <cgi.h>
//content-type: text/html

/*
* saveScore 使い方
*	saveScore(名前（Char型配列）,　スコア(int型), 日付(char型配列));
*　戻り値はint 1 or 0 で　1 ならfileWrite成功です。
*/

int saveScore(char* name,int score,char* date){


	FILE *fp;	/* (1)ファイルポインタの宣言 */
	/* (2)ファイルのオープン */
	/*  ここで、ファイルポインタを取得する */
	if ((fp = fopen("history.txt", "a")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
	}
	/* (4)ファイルの読み（書き）*/
	fprintf(fp,"%s %d %s\n",name,score,date);
	//fprintf(fp,name);
	fclose(fp);	/* (5)ファイルのクローズ */

	return 1;
}

int main(void)
{
	printf( "content-type: text/html\n\n");
	//printf(HTML_HEADER("UTF-8")); /* Web ページの文字コードは UTF-8 が一般的 */
  printf("<html>\n<body>\n");

	char name[256] = "hello";
	int score = 3000;
	char date[30] = "2017/4/25"; // date[0] = year date[1] = month date[2] = day
	//ファイル出力結果
	int fwresult;

  //name = "hello";

	printf(
"    <h1>Save your score!</h1>\n\
	<form action=\"/~inamoto/cgi-bin/CGI-simple-dump.cgi\" method=\"POST\">\n\
      <h2>input</h2>\n\
      <ul>\n\
	<li>type 属性がtext <input type=\"text\" value=\"input plz.\" name=\"POST-text\">\n\
	</li>\n\
\n\
      <h2>textarea</h2>\n\
      <textarea name=\"POST-textarea\">テキストエリア</textarea>\n\
      <br>\n\
      <input type=\"submit\" value=\"送信\"> <input type=\"reset\" value=\"リセット\">\n\
    </form>");



	fwresult = saveScore(name,score,date);
	if(fwresult){
		printf("File write Success\n");
	}else {

	}	

 printf( "\n</body>\n</html>\n");
	

	return 0;
}

