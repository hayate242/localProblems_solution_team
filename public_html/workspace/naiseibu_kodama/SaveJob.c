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
  fp = fopen("parttimejob.txt", "a+");
  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */
  if (vars) {
      /* 変数名と復号化された値を出力 */
    fprintf(fp, "%s %s\n", cgiGetValue(cgi, vars[0]), cgiGetValue(cgi, vars[1]));
  }
  cgiFreeList(vars);
  fclose(fp);
  
  /*
  int data_size;  
  int i, j;
  char jobname[16];
  int jobmoney[10];
  FILE *fp;
  char *buf = NULL;	 
  char *cp;

  puts(HTML_HEADER("UTF-8"));
  puts("<html><body>");

  if ((cp = getenv("REQUEST_METHOD")) && (! strcmp(cp, "GET"))) {
    cp = getenv("QUERY_STRING");
    assert(cp);
    data_size = strlen(cp);
    buf = (char*)malloc(data_size + 1);
    memcpy(buf, cp, data_size + 1);
  } else {
    fprintf(stderr, "invalid method: %s\n", cp);
    exit(EXIT_FAILURE);
  }

  printf("form data follows:<br>\n");
  fputs(buf, stdout);
  printf("%c", buf[35]);

  i = 0;
  while(buf[i] != '='){
    i++;
  }
  i++;
  j = 0;
  while(buf[i] != '&'){
    jobname[j] = buf[i];
    j++; i++;
  }
  j++;
  jobname[j] = '\0';
  
  while(buf[++i] != '='){
    i++;
  }
  j = 0;
  
  fp = fopen("parttimejob.txt", "a+");
  fprintf(fp, "%s\n", jobname);
  fclose(fp);

  puts("\n</body></html>");

  free(buf);
  */
  
  return 0;
 }
