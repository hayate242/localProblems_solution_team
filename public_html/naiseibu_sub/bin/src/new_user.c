#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <cgi.h>

struct data{
  char id[16];
  char pass[16];
};

int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars, **files, c, buf[1024];
  struct data data[100];
  int i, bWord=0, id=0, pass=0, flag;
  FILE *fp;

  cgi = cgiInit();	
  cgiSetType("text/html; charset=UTF-8"); 
  cgiHeader();		
  vars = cgiGetVariables(cgi);

  printf("<html>");

  printf(" <head><link rel=\"stylesheet\" href=\"css/bgcolor.css\"><title>新規登録</title></head>\n<body>");
  if(vars){
    if (cgiGetValue(cgi, vars[0]) == '\0' || cgiGetValue(cgi, vars[1]) == '\0'){
      printf("<p align=\"center\"><font color=\"white\">全ての項目を入力してください</font></p>\n");
    }

    else{
      fp = fopen("account.txt","r");
      if(fp == NULL){
        printf("サーバー側でエラーが発生しています。\n");
      }
      else{
        i = 0;
        flag = 0;
        while(fscanf(fp, "%s %s", data[i].id, data[i].pass) != EOF){
          if (strcmp(data[i].id, cgiGetValue(cgi, vars[0]))==0){
            printf("<p align=\"center\"><font color=\"red\">既に使用されているユーザー名です</font></p>\n");        
            flag = 1;
            break;
          }
          i++;
        }
        if (flag == 0){
          printf("<meta  http-equiv=\"refresh\" content=\"0.3;URL=SaveID.cgi?ID=%s&pass=%s\">", cgiGetValue(cgi, vars[0]), cgiGetValue(cgi, vars[1]));
        }
      }
    }
  }
  printf("\n<h1 align=\"center\">新規登録</h1>");
  printf("<br><br>\n<form action=\"new_user.cgi\" method=\"GET\">\n<table align=\"center\" style=\"font-size:20px\">\n<tr>\n<td>ID:</td><td><input type=\"text\" name=\"ID\"></td>\n</tr>\n<tr>\n<td>Pass:</td><td><input type=\"password\" name=\"pass\"></td>\n</tr>\n<tr>\n<td align=\"center\" colspan=\"2\"><input type=\"submit\" value=\"登録\"></td>\n</tr>\n</table>\n</form>\n<br>\n<font size=\"5px\">\n<p align=\"center\"><a href=\"login.cgi\">戻る</a></p>\n</font>\n</body>\n");

  printf("</html>");
  
  return 0;
}