#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_STR "Content-type: text/html; charset=UTF-8\n\n"
#define END_STR "\n</body></html>\n"

struct info{
  char name[16];  //名前を格納しています。
  int score;      //スコアを格納しています。
  char date[20];  //プレイ日時を格納しています。
};

void SortScore( struct info *data, int length ){
  struct info tmp;
  int i, j;

  for ( i = 0; i < length; i++ ){
    for ( j = i+1; j < length; j++ ){
      if ( data[i].score < data[j].score ){
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
      }
    }
  }
}

/*
[history.txt]
・ゲームのプレイヤーの名前、スコア、プレイ日時が記述されています。
・名前、スコア、プレイ日時を、空白「" "」で区切っています。
[table.css]
・ランキング表の表示を変更しています。
・cgiファイルと同じディレクトリに設置しています。
*/

int main(void){
  FILE *fp = NULL;
  struct info data[512];
  int length;
  int i, j;

  fp = fopen("history.txt", "r");  //cgiファイルと同じディレクトリにhistory.txtを置いています。

  if (fp == NULL) {  //history.txtが存在しなければエラーメッセージが表示されます。
    printf("ファイルが開けません\n");
    return -1;
  }
  
  i = 0;  //history.txtから全ての行のプレイヤーデータを取り出しています。
  while (fscanf(fp, "%s %d %s", data[i].name, &data[i].score, data[i].date) != EOF){
    i++;
  }
  length = i;
  
  SortScore(data, length);  //プレイヤーデータのスコアが降順になるように並び替えます。

  i = 0;  //ランキング表を表示します（cssファイル名ははtable.cssです）。
  puts(START_STR);
  printf("<html>\n"
	 "<head>\n"
	 "<link rel=\"stylesheet\" type=\"text/css\" href=\"table.css\">\n"
	 "</head>\n"
	 "<body>\n");
  printf("<table>\n");
  printf("<tr><th colspan=\"4\">プレイヤーランキング</th></tr>");
  printf("<tr><th>No.</th><th>NAME</th><th>SCORE</th><th>DATE</th></tr>\n");
  while (i != length && i != 10){
    printf("<tr><td>%d</td><td>%s</td><td>%d</td><td>%s</td><tr>\n", i+1, data[i].name, data[i].score, data[i].date);
    i++;
  }
  printf("</table>\n");
  printf(END_STR);
  return 0;
}
