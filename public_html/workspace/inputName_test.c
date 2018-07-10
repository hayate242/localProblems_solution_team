/* フォームデータをたんに出力するプログラム */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <cgi.h>

#define HTML_HEADER(CHAR_SET) \
  "Content-type: text/html; charset=" CHAR_SET "\n\n"

int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars;


  cgi = cgiInit();		/* cgilib の初期化 */
	cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();			/* HTTP ヘッダを出力 */
  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */


  puts("<html><body>");
	
	


/* フォームデータを処理．今回はそのまま出力 */

	printf("%s",cgiGetValue(cgi, vars[0]));
	puts("<h1>Save your score!</h1>	<form action=\"saveScore.cgi?");
	
	

	printf("&\" method=\"GET\">      <h2>名前を入力してください</h2>      <ul>	<li><input type=\"text\" value=\"\" name=\"name\">	    <input name=\"score\" value=\"%s\" >  <input type=\"submit\" value=\"送信\"> </form>", cgiGetValue(cgi, vars[0]));

  

  puts("\n</body></html>");


  
  return 0;
 }
