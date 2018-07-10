#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//
//		頼むからscoreに0を入れないで
//
typedef struct history {
	char name[100];
	int score;
	char date[20];
} History;

void sortScore( History data[1000] ){

	int i,j;
  int length = 0;
	History tmp;

	//構造体の長さを求める
	i = 0;
	while(data[i].score != 0){
		length++;
		i++;
	}
	printf("length = %d\n",length);

	// for(i = 0; i < length; i++){
	// 	printf("名前　%s 日付　%s\n",name[i],date[i]);
	// }

	for( i = 0; i < length; i++ ){
		for(j = i+1; j < length; j++){
			if(data[i].score < data[j].score){
				//swap( &score[i], &score[j] );
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
				// printf();

			}
		}
	}
	
	printf("ソート後\n");
	for(i = 0; i < length; i++){
		printf("%s, %d, %s\n", data[i].name, data[i].score, data[i].date);
	}


}



int main(void){
  FILE *fp = NULL;
  History data[1000];
  int i;
	int ret;
	int length = 0;

  fp = fopen("history.txt", "r");
  if (fp == NULL) {
    printf("ファイルが開けません\n");
    return -1;
  }

  i = 0;
  while( (ret = fscanf(fp,"%s %d %s",data[i].name,&data[i].score,data[i].date)) != EOF ){
    // fscanf(fp,"%s %d %s",data[i].name,&data[i].score,data[i].date);
		length++;
    i++;
  }

	for(i = 0; i < length; i++){
		printf("%s %d %s\n",data[i].name,data[i].score,data[i].date);
	}

	sortScore(data);

  return 0;
}
