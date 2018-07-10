#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <cgi.h>

int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars, **files, c, buf[1024];
  int i, bWord=0, id=0, pass=0;
  FILE *fp;

  cgi = cgiInit();	
  cgiSetType("text/html; charset=UTF-8"); 
  cgiHeader();		

  printf("<html>");

  printf(" <head><title>新規登録</title></head>\n");

  printf("<body>\n<h1 align=\"center\">新規登録</h1><br><br>\n<form action=\"SaveID.cgi\" method=\"GET\">\n<table align=\"center\" style=\"font-size:20px\">\n<tr>\n<td>ID:</td><td><input type=\"text\" name=\"ID\"></td>\n</tr>\n<tr>\n<td>Pass:</td><td><input type=\"password\" name=\"pass\"></td>\n</tr>\n<tr>\n<td align=\"center\" colspan=\"2\"><input type=\"submit\" value=\"登録\"></td>\n</tr>\n</table>\n</form>\n<br>\n<font size=\"5px\">\n<p align=\"center\"><a href=\"schedule_login.cgi\">戻る</a></p>\n</font>\n</body>\n");

  printf("</html>");

  return 0;
}
