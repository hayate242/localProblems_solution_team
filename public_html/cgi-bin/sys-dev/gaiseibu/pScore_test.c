#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct history {
	char name[100];
	int score;
	char date[20];
} History;

void sortScore( History data[1000] ){

	int i,j;
  int length = 0;
	int tmp;
	char *tmpChar;
	//配列の長さを求める
	length = sizeof(struct history);
	printf("length = %d\n",length);

	// for(i = 0; i < length; i++){
	// 	printf("名前　%s 日付　%s\n",name[i],date[i]);
	// }

	// for( i = 0; i < length; i++ ){
	// 	for(j = i+1; j < length; j++){
	// 		if(score[i] < score[j]){
	// 			//swap( &score[i], &score[j] );
	// 			tmp = score[i];
	// 			score[i] = score[j];
	// 			score[j] = tmp;
	// 			// printf();
	//
	// 			tmpChar = name[i];
	// 			name[i] = name[j];
	// 			name[j] = tmpChar;
	//
	// 			tmpChar = date[i];
	// 			date[i] = date[j];
	// 			date[j] = tmpChar;
	//
	// 		}
	// 	}
	// }
	for(i = 0; i < length; i++){
		printf("%s, %d, %s\n", data[i].name, data[i].score, data[i].date);
	}


}



int main(void){
  FILE *fp = NULL;
  History data[1000];
  int i;
	int ret;

  fp = fopen("history.txt", "r");
  if (fp == NULL) {
    printf("ファイルが開けません\n");
    return -1;
  }

  i = 0;
  while( (ret = fscanf(fp,"%s %d %s",data[i].name,&data[i].score,data[i].date)) != EOF ){
    // fscanf(fp,"%s %d %s",data[i].name,&data[i].score,data[i].date);
    i++;
  }

	for(i = 0; i < 11; i++){
		printf("%s %d %s\n",data[i].name,data[i].score,data[i].date);
	}

	sortScore(data);

  return 0;
}
