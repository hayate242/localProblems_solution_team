#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HTML_HEADER(CHAR_SET) "Content-type:text/html; charset="CHAR_SET"\n\n"

struct job{
  char Jobname[16];
  int wage;
};

int main(void){
  FILE *fp;
  struct job data[100];
  int i, length;
  
  printf(HTML_HEADER("UTF-8"));
  printf("<html>\n<body>\n<h2>現在の設定</h2>\n<table border=1 cellpadding=0 cellspacing=0>\n<tr><th>バイト名</th><th>時給</th></tr>\n");

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
  while (i != length){
    printf("<tr><td>%s</td><td>%d円</td></tr>\n", data[i].Jobname, data[i].wage);
    i++;
  }
  printf("</table>\n");
  printf("<td><form action=\"/~e1530koda/cgi-bin/sys-dev/naiseibu/DeleteJob.cgi\" method=GET>");
  printf("<input type=\"text\" name=\"number\" size=5>");
  printf("<input type=\"submit\" value=\"削除\"></form>");

  printf("<h2>勤務先の登録</h2>\n<form action=\"/~e1530koda/cgi-bin/sys-dev/naiseibu/SaveJob.cgi\" method=\"GET\">\nバイト名:<input type=\"text\" name=\"Jobname\" size=20><br>\n時給:<input type=\"text\" name=\"Jobmoney\" size=20><br>\n<input type=\"reset\" value=\"クリア\">\n<input type=\"submit\" value=\"登録\">\n</form>\n</body>\n</html>\n");

  return 0;
}
