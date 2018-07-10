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
/*

＊ログインページの説明＊

必要なファイル：
 account.txt(登録できるid,passは100個までとしておきましょう)
 login.cgi(このファイルをコンパイルしたcgiファイル)

動作：
フォームからIDとパスワードを入力する。
 1.どちらかが未入力の場合
  ”全ての項目を入力してください”というメッセージを表示し、再びフォーム画面を表示する。
 2.入力に不備がある場合
  "IDもしくはパスワードが間違っています"というメッセージを表示し、再びフォーム画面を表示する。
 3.入力が正しい場合
  メインページ(index.html?name=ユーザ名)へ遷移する。
 例外.登録されたIDとパスワードを記録しているテキストファイル(account.txt)が開けない場合
  "サーバー側でエラーが発生しています"というメッセージを表示し、再びフォーム画面を表示する。

 */

int main(int argc, char **argv)
{
  s_cgi *cgi;
  char **vars;
  struct data data[100];  //登録できるid,passは100個までになっている。
  int i, flag;
  FILE *fp;

  cgi = cgiInit();	
  cgiSetType("text/html; charset=UTF-8"); 
  cgiHeader();
  vars = cgiGetVariables(cgi);
  
  printf("<html><head><title>ログイン</title><link rel=\"stylesheet\" href=\"css/bgcolor.css\"></head>\n<body>\n");
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
	  if (strcmp(data[i].id, cgiGetValue(cgi, vars[0]))==0 && strcmp(data[i].pass, cgiGetValue(cgi, vars[1]))==0){
	    printf("<meta http-equiv=\"refresh\" content=\"0.3;URL=index.html?name=%s\">", data[i].id);
	    /*
	    printf("<p align=\"center\"><a href=\"main.html?name=%s\">ようこそ俺のバイト代へ！</a></p>", data[i].id);
	    */
	    flag = 1;  //メインページへ遷移するリンク（上記のprintf関数の中身）を使用する場合、必要になる
	    break;
	  }
	  i++;
	}
	if (flag == 0){
	  printf("<p align=\"center\"><font color=\"white\">IDもしくはパスワードが間違っています。</font><p>\n");
	} 
      }
      fclose(fp);
    }
    cgiFreeList(vars);
    cgiFree(cgi); 
  }
  
  printf("<h1 align=\"center\">ログイン</h1><br><br>\n<form action=\"login.cgi\" method=\"POST\">\n<table align=\"center\" style=\"font-size:20px\">\n<tr>\n<td>ID:</td><td><input type=\"text\" name=\"ID\"></td>\n</tr>\n<tr>\n<td>Pass:</td><td><input type=\"password\" name=\"pass\"></td>\n</tr>\n<tr>\n<td align=\"center\" colspan=\"2\"><input type=\"submit\" value=\"login\"></td>\n</tr>\n</table>\n</form>\n<br>\n<font size=\"5px\">\n<p align=\"center\"><a href=\"new_user.cgi\">新規登録</a>はこちら！</p>\n</font></body></html>");
  return 0;
}
