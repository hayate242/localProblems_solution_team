/* 実行するたびに 1-6 の数字を表示するプログラム */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define HTML_HEADER(CHAR_SET) \
  "Content-type: text/html; charset=" CHAR_SET "\n\n"

int main(void)
{
  const time_t now = time(NULL); /* 時刻を取得 (cf. man -a time) */
  int num;
  
  srand((unsigned)now);		/* 擬似乱数系列の初期値を設定 */

  num = rand() % 6 + 1;		/* サイコロを振る */

  /* ページの文字コードは UTF-8 とする */
  puts(HTML_HEADER("UTF-8"));
  puts("<html><body>");

  /* HTML による記述を出力 */
  printf("<p>seed = %ld; dice = %d</p>\n", now, num);

  puts("<form action=\"/~inamoto/cgi-bin/CGI-dice.cgi\" method=\"GET\">\n"
       " <input type=\"submit\" value=\" もう一度振る \">\n"
       "</form>"
       "</html></body>");

  return 0;
}
