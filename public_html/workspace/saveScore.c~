#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <cgi.h>
#include <time.h>

#define HTML_HEADER(CHAR_SET) \
  "Content-type: text/html; charset=" CHAR_SET "\n\n"
//content-type: text/html

/*
* saveScore 使い方
*	saveScore(名前（Char型配列）,　スコア(int型), 日付(char型配列));
*　戻り値はint 1 or 0 で　1 ならfileWrite成功です。
*/

int saveScore(char* name,char* score,char* date){


	FILE *fp;	/* (1)ファイルポインタの宣言 */
	/* (2)ファイルのオープン */
	/*  ここで、ファイルポインタを取得する */
	if ((fp = fopen("history.txt", "a")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
	}
	/* (4)ファイルの読み（書き）*/
	fprintf(fp,"%s %s %s\n",name,score,date);
	//fprintf(fp,name);
	fclose(fp);	/* (5)ファイルのクローズ */

	return 1;
}

int main(int argc, char **argv)
{
	s_cgi *cgi;
  char **vars;

	char *date = "2017/6/26";

//ファイル出力結果
	int fwresult;

    

  cgi = cgiInit();		/* cgilib の初期化 */
	cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();			/* HTTP ヘッダを出力 */
  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */
  printf("<html>\n<body>\n");



	

  //name = "hello";



	fwresult = saveScore(cgiGetValue(cgi, vars[0]),cgiGetValue(cgi, vars[1]),date);
	if(fwresult){
		printf("登録完了\n");
		printf("<a href=\"PrintScore.cgi\" class=\"top\">ランキングを見る→</a>");
	}else {

	}	

 printf( "\n</body>\n</html>\n");
	

	return 0;
}

