/***
    Copyright (C) INAMOTO Tsutomu & Ehime University

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
***/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <cgi.h>

#define START_STR "<html><head> <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />" \
"    <title> カウンタ </title>"	"  </head>" "  <body>"
#define END_STR "\n</body></html>\n"

#define COUNTER_NAME "inc_value" /* form タグで与えられる変数名 */
#define COUNTER_FILE "/home/inamoto/public_html/cgi-data/work-01/counter.txt" /* カウンタファイルの指定 */
#define COUNTER_CGI "/~inamoto/cgi-bin/work-01/counter.cgi" /* CGI プログラム */

int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars, *inc_value = NULL, buf[BUFSIZ];
  int value = 0;
  FILE *fp = NULL;

  cgi = cgiInit();		/* cgilib の初期化 */
  cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();				  /* http ヘッダの出力 */

  if ((vars = cgiGetVariables(cgi))) { /* データが与えられていれば */
    inc_value = cgiGetValue(cgi, COUNTER_NAME);
  }

  if ((fp = fopen(COUNTER_FILE, "r"))) {
    if (fscanf(fp, "%d", &value) != 1) {
      printf("ファイル: %s の読み取りに失敗 (%s)\n", COUNTER_FILE, strerror(errno));
      exit(EXIT_FAILURE);
    }
    fclose(fp);
  }

  if (inc_value) {
    value += atoi(inc_value);	/* 文字列を整数へ変換し，カウンタを増減 */
  }
  sprintf(buf, "%d", value);	/* 表示用文字列を設定 */

  puts(START_STR);
  printf("<h1> カウンタ </h1>"	       \
	 "<form action=\"%s\" method=\"POST\"> \
      <p> カウンタの値 : %s </p>  <p> カウンタの増減 : </p> <ul>	\
        <li> +1 <input type=\"radio\" value=\"1\" name=\"inc_value\"> </li> \
        <li> 0 <input type=\"radio\" value=\"0\" name=\"inc_value\" checked> </li> \
        <li> -1 <input type=\"radio\" value=\"-1\" name=\"inc_value\"> </li> \
      </ul> <input type=\"submit\" value=\" 実行 \">  </form> </body> </html>", COUNTER_CGI, buf);
  
  if (! (fp = fopen(COUNTER_FILE, "w"))) {
    printf("ファイル: %s の書き込み用オープンに失敗 (%s)\n", COUNTER_FILE, strerror(errno));
    exit(EXIT_FAILURE);
  }
  if (fprintf(fp, "%d", value) <= 0) {
    printf("ファイル: %s への書き込みに失敗 (%s)\n", COUNTER_FILE, strerror(errno));
    exit(EXIT_FAILURE);
  }
  fclose(fp);
  puts(END_STR);

  return EXIT_SUCCESS;
}

