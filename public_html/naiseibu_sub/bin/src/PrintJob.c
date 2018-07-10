#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cgi.h>

/*
#define HTML_HEADER(CHAR_SET) "Content-type:text/html; charset="CHAR_SET"\n\n"
*/

struct job{
  char username[25];
  char Jobname[25];
  int wage;
};

int main(void){
  s_cgi *cgi;
  char **vars, **files;
  FILE *fp;
  struct job data[100];
  int i, length, cnt;

  cgi = cgiInit();
  cgiSetType("text/html; charset=UTF-8");
  cgiHeader();
  vars = cgiGetVariables(cgi);
  printf("<!DOCTYPE html><html lang=\"ja\"><head><meta charset=\"UTF-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><title>俺のバイト代</title><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><meta name=\"description\" content=\"俺のバイト代\"><meta name=\"keywords\" content=\"バイト,履歴,保存,グラフ,お金持ち\"><link rel=\"stylesheet\" href=\"css/style.css\"><script type=\"text/javascript\" src=\"js/openclose.js\"></script><script type=\"text/javascript\">  var username;  function getdata(){    if(window.location.search){        /* URLの「?」以降のパラメータを変数nに代入 */        var n=window.location.search.substring(1,window.location.search.length);        /* テキストボックスにパラメータを表示 */      // document.form3.elements[\"getpram\"].value=n;          username = n.replace(\"name=\",\"\");          console.log(username);    }  }  /* オンロード時に実行 */  window.onload=getdata;  </script></head><body><div id=\"container\"><header><h1 id=\"logo\"><a href=\"index.html?name=%s\"><img src=\"images/busy.png\" alt=\"About us\"></a></h1></header><nav id=\"menubar\"><ul>  <li><a href=\"index.html?name=%s\">ホーム</a></li>  <li><a href=\"PrintJob.cgi?name=%s\">勤務一覧</a></li>  <li><a href=\"gallery.html?name=%s\">About us</a></li></ul></nav><div id=\"contents\"><section><h2>登録状況</h2><table class=\"ta1\"><tr><td>行番号</td><td>バイト名</td><td>時給</td></tr>",cgiGetValue(cgi, vars[0]),cgiGetValue(cgi, vars[0]),cgiGetValue(cgi, vars[0]),cgiGetValue(cgi, vars[0]));

  fp = fopen("parttimejob.txt", "r");
  if (fp == NULL){
    printf("ファイルが開けません\n");
  }

  i = 0;
  cnt = 0;
  while ((fscanf(fp, "%s %s %d", data[i].username, data[i].Jobname, &data[i].wage)) != EOF){
    if (strcmp(cgiGetValue(cgi, vars[0]), data[i].username) == 0){
      cnt++;
      printf("<tr><td>%d</td><td>%s</td><td>%d円</td></tr>\n", cnt,  data[i].Jobname, data[i].wage);
    }
    i++;
  }
  /*
  length = i;

  i = 0;
  while (i != length){
    printf("<tr><td>%s</td><td>%d円</td></te>\n", data[i].Jobname, data[i].wage);
    //  printf("<form action=\"/e1542taba/develop/SaveJob.cgi\" method=\"GET\">");
    i++;
    }*/
  printf("</table>\n");

	



  printf("<h2>勤務先の登録</h2>\n<form action=\"SaveJob.cgi\" method=\"GET\">\nバイト名:<input type=\"text\" name=\"Jobname\" size=20><br>\n時給:<input type=\"text\" name=\"Jobmoney\" size=20><br>\n<input type=\"hidden\" name=\"name\" value=\"%s\"><input type=\"reset\" value=\"クリア\">\n<input type=\"submit\" value=\"登録\">\n</form><br><br>\n\n\n", cgiGetValue(cgi, vars[0]));

  printf("削除したい行番号<form action=\"DeleteJob.cgi\" method=\"GET\">\n");
  printf("<input type=\"text\" name=\"number\" size=20>\n<input type=\"submit\" value=\"削除\">\n<input type=\"hidden\" name=\"name\" value=\"%s\"></form></td></tr>", cgiGetValue(cgi, vars[0]));
  printf("<a href=\"index.html?name=%s\">戻る</a>", cgiGetValue(cgi, vars[0]));


	printf("</section><footer><small>Copyright&copy; <a id=\"index.html\" onclick=\"moveToOtherPage(this.id)\">俺のバイト代</a> All Rights Reserved.</small><!-- <span class=\"pr\">《<a href=\"http://template-party.com/\" target=\"_blank\">Web Design:Template-Party</a>》</span> --></footer></div><!--/container--></body></html>");

  return 0;
}
