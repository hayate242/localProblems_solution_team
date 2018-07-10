#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        int chr;
        int flag;

// 環境変数を取得
        char *get = "GET";
        char *post = "POST";
        char *method;
        method = getenv("REQUEST_METHOD");
        // printf("method=%s\n",method);

// 環境変数を比較，設定されていないなら”terminal”と出力して終了する
        if(strcmp(method,"") == 0){
          printf("terminal");
          exit(0);
        }else{
          printf("content-type: text/html\n\n");
        }
// get methodならREQUEST_METHODと環境変数「QUERY_STRING」の値を端末へ出力しexit(0)，そうでなければ"oops"と出力してexit(1)で終了
        if(strcmp(method,get) == 0){
          printf("method=%s\n",method);
          printf("%s\n", getenv("QUERY_STRING"));
          exit(0);
        } else{
          printf("method=%s\n",method);
          printf("oops\n");
          exit(1);
        }

        // POSTの時取得して出力
        // if(strcmp(method,post) == 0){
        //   printf("Content-type: text/html\n\n");
        //   printf("<HTML><BODY>\n");
        //   printf("cgi3.cgi<BR>\n");
        //
        //   flag = 0;
        //   while( flag == 0 )
        //   {
        //           /* 渡されたデータを標準入力より取得する */
        //           chr = getchar();
        //           /* 渡されたデータをそのまま表示する */
        //           putchar(chr);
        //           /* データ終了のチェック */
        //           if( (chr == EOF) || (chr == 0x00) || (chr == '\n') )
        //           {
        //                   flag = 1;
        //           }
        //   }
        //
        //   printf("</BODY></HTML>\n");
        // }


        return 0;

}

