#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define HTML_HEADER(CHAR_SET) \
  "Content-type: text/html; charset=" CHAR_SET "\n\n"

int main(void)
{
  int data_size;		/* フォームデータのデータサイズ */
  char *buf = NULL;	      /* フォームデータを保持しておくところ */
  char *cp;

  puts(HTML_HEADER("UTF-8")); /* Web ページの文字コードは UTF-8 が一般的 */
  puts("<html><body>");

  if ((cp = getenv("REQUEST_METHOD")) && (! strcmp(cp, "GET"))) {
    /* 送信方法は GET ．環境変数から読み取る */
    cp = getenv("QUERY_STRING");
    assert(cp);
    data_size = strlen(cp);	/* サイズを取得 */
    buf = (char*)malloc(data_size + 1); /* メモリを確保．\0 用に +1 */
    memcpy(buf, cp, data_size + 1); /* データを取得 */
  } else {
    fprintf(stderr, "invalid method: %s\n", cp);
    exit(EXIT_FAILURE);
  }

  /* フォームデータを処理．今回はそのまま出力 */
  printf("form data follows:<br>\n");
  fputs(buf, stdout);

  puts("\n</body></html>");

  free(buf);			/* メモリを解放 */
  
  return 0;
 }
