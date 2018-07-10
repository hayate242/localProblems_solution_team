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
  char **vars, **files;
  int i;
  FILE *fp;

  cgi = cgiInit();		/* cgilib の初期化 */
  cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();			/* HTTP ヘッダを出力 */
  
  puts("<html><body>");
  fp = fopen("account.txt", "a+");
  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */
  if (vars) {
      /* 変数名と復号化された値を出力 */
    fprintf(fp, "%s %s\n", cgiGetValue(cgi, vars[0]), cgiGetValue(cgi, vars[1]));
  }
 printf("登録完了<br>");
 printf("<a href=\"schedule_login.cgi\">戻る</a>");

 puts("</body></html>");
  cgiFreeList(vars);
  fclose(fp);
  

  
  return 0;
 }
