#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include <cgi.h>

struct data{
  char id[16];
  char pass[16];
};

int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars, **files, c, buf[1024];
  int i, bWord=0, id=0, pass=0;
  FILE *fp;

  cgi = cgiInit();	
  cgiSetType("text/html; charset=UTF-8"); 
  cgiHeader();		

  puts("<html><body>");

  vars = cgiGetVariables(cgi);
 
  
  if(cgiGetValue(cgi, vars[0]) == '\0'|| cgiGetValue(cgi, vars[1]) == '\0'){
 
    printf("全ての項目を入力してください<br><br>\n");
    printf("<a href=\"schedule_1.html\">戻る</a>");
    printf("</body></html>\n");
    return -1;
  }
  
  fp = fopen("account.txt","r");
  if(fp == NULL){
    printf("ファイルが開けませんでした\n");
  }

  struct data data[100];
  i = 0;
  while(fscanf(fp, "%s %s", data[i].id, data[i].pass) != EOF){
    if (strcmp(data[i].id, cgiGetValue(cgi, vars[0]))==0 && strcmp(data[i].pass, cgiGetValue(cgi, vars[1]))==0){
      printf("<table width=\"90%\" height=\"90%\" align=\"center\"><tr><td><font size=\"7\"><div align=\"center\">");
      printf("<a href=\"index.html?name=%s\">ようこそ俺のバイト代へ！</a>", data[i].id);
      printf("</div></font></td></tr></table>");
      puts("</html></body>");
      return 0;
    }
    i++;
  }
  printf("間違っています");
  printf("<a href=\"schedule_login.cgi\">戻る</a>");
  puts("</html></body>");
 
  cgiFreeList(vars);
  fclose(fp);
  cgiFree(cgi);

  return 0;
}
