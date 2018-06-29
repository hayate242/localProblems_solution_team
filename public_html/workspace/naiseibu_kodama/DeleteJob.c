#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <cgi.h>

struct job{
  char Jobname[16];
  int wage;
};


int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars, **files;
  FILE *fp;
  struct job data[100];
  int i, length, cnt;//cntは渡された番号
  
  cgi = cgiInit();		/* cgilib の初期化 */
  cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();			/* HTTP ヘッダを出力 */
  
  puts("<html><body>");
  
  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */
  if (vars) {
    cnt = atoi(cgiGetValue(cgi, vars[0]));
    cnt--;
  }
  
  cgiFreeList(vars);		/* メモリを解放 */
  
  fp = fopen("parttimejob.txt", "r");
  if (fp == NULL){
    printf("ファイルが開けません\n");
  }
  
  i = 0;
  while ((fscanf(fp, "%s %d", data[i].Jobname, &data[i].wage)) != EOF){
    i++;
  }
  length = i;
  i = 0;
  fclose(fp);
  
  fp = fopen("parttimejob.txt", "w");
  
  while(i != length){
    if(i == cnt){
      i++;
      continue;
    }
    fprintf(fp, "%s %d\n", data[i].Jobname, data[i].wage);
    i++;
  }
  
  fclose(fp);
  printf("</body></head>");
}

