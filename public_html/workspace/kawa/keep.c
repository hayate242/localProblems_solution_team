/* 変数を保持し続ける */

#define VAR_NAME "remaining"
#define NEW_NAME "new_name"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cgi.h>

int main(void)
{
  s_cgi *cgi;
  char **vars, *cp;
  char var_value[1024] = "";	/* サイズ固定 */
  int i;

  cgi = cgiInit();		/* cgilib の初期化 */
  cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();			/* HTTP ヘッダを出力 */

  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */
  if (vars) {
    for (i = 0; vars[i]; i++) {
      if (! strcmp(vars[i], VAR_NAME)) {
	strncpy(var_value, cgiGetValue(cgi, VAR_NAME), sizeof(var_value)); /* 変数の値をコピー */
	break;
      }
    }
    cgiFreeList(vars);		/* メモリを解放 */
  }

  if ((cp = cgiGetValue(cgi, NEW_NAME)) && strcmp(cp, "")) { /* べつの所定の変数が空でなければ */
    strncpy(var_value, cp, sizeof(var_value)); /* 変数の値を変更 */
  }

  printf("<html><body><p> %s = %s</p>", VAR_NAME, var_value); /* 値を参考までに表示 */
  printf("<form action=\"/~inamoto/cgi-bin/CGI-hidden.cgi\" method=\"POST\">");
  printf("新しい値 : <input type=\"text\" value=\"\" name=\"%s\">", NEW_NAME);
  if (strcmp(var_value, "")) {
    printf("<input type=\"hidden\" name=\"%s\" value=\"%s\">",
	   VAR_NAME, var_value); /* hidden 変数として保持 */
  }
  puts("<input type=\"submit\" value=\" 実行 \"></form></body></html>");

  cgiFree(cgi);			/* メモリを解放 */

  return EXIT_SUCCESS;
}
