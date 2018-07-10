#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <cgi.h>

struct job{
  char username[25];
  char Jobname[25];
  int wage;
};


int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars, **files;
  FILE *fp;
  struct job data[100];
  int i, length, length2, cnt, cnt2;//cntは渡された番号
  
  cgi = cgiInit();		/* cgilib の初期化 */
  cgiSetType("text/html; charset=UTF-8"); /* 文字コードを UTF-8 に */
  cgiHeader();			/* HTTP ヘッダを出力 */
  puts("<html><head><link rel=\"stylesheet\" href=\"css/bgcolor.css\"></head><body>");
  
  vars = cgiGetVariables(cgi);	/* 変数名の一覧を取得 */
  if (vars) {
    cnt = atoi(cgiGetValue(cgi, vars[0]));
  }
  fp = fopen("parttimejob.txt", "r");
  if (fp == NULL){
    printf("ファイルが開けません\n");
  }
  
  i = 0;
  cnt2 = 0;
  while ((fscanf(fp, "%s %s %d\n", data[i].username, data[i].Jobname, &data[i].wage)) != EOF){
    if (strcmp(cgiGetValue(cgi, vars[1]), data[i].username) == 0){
      cnt2++;
      if (cnt == cnt2){
	length2 = i;
      }
    }
    i++;
  }
  length = i;
  i = 0;
  fclose(fp);
  
  fp = fopen("parttimejob.txt", "w");
  while(i != length){
    if(i == length2){
      i++;
      continue;
    }
    fprintf(fp, "%s %s %d\n", data[i].username, data[i].Jobname, data[i].wage);
    i++;
  }
	fclose(fp);

	
  i = 0;
	fp = fopen("registared_baito.txt", "w");
  while(i != length){
    if(i == length2){
      i++;
      continue;
    }
    fprintf(fp, "%s,%s,%d,\n", data[i].username, data[i].Jobname, data[i].wage);
    i++;
  }




  printf("削除しました<br>");
  printf("<a href=\"PrintJob.cgi?name=%s\">戻る</a>", cgiGetValue(cgi, vars[1]));
  fclose(fp);
  cgiFreeList(vars);		/* メモリを解放 */
  printf("</body></head>");
  return 0;
}

