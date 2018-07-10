#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int sortScore( char** name, int* score,char** date ){

	int i,j;
  int length = 0;
	int tmp;
	char *tmpChar;
	//配列の長さを求める
	i = 0;
	while(name[i] != '\0'){
		length++;
		i++;
	}
	printf("%d\n",length);

	// for(i = 0; i < length; i++){
	// 	printf("名前　%s 日付　%s\n",name[i],date[i]);
	// }

	for( i = 0; i < length; i++ ){
		for(j = i+1; j < length; j++){
			if(score[i] < score[j]){
				//swap( &score[i], &score[j] );
				tmp = score[i];
				score[i] = score[j];
				score[j] = tmp;
				// printf();

				tmpChar = name[i];
				name[i] = name[j];
				name[j] = tmpChar;

				tmpChar = date[i];
				date[i] = date[j];
				date[j] = tmpChar;

			}
		}
	}
	for(i = 0; i < length; i++){
		printf("%s, %d, %s\n", name[i], score[i], date[i]);
	}

	return 1;
}



int main(void){
  FILE *fp = NULL;
  char str[100];
  char *name[100];
  char *score[100];
  char *date[100];
  int H_score[100];
  int i;

  fp = fopen("history.txt", "r");
  if (fp == NULL) {
    printf("ファイルが開けません\n");
    return -1;
  }

  i = 0;
  while(fgets(str, 100, fp) != NULL){
    name[i] = strtok(str, " ");
    score[i] = strtok(NULL, " ");
    H_score[i] = atoi(score[i]);
    date[i] = strtok(NULL, " ");
    printf("%s, %d, %s\n", name[i], H_score[i], date[i]);
		printf("i = %d\n",i);
    i++;
  }

	for(i = 0; i < 11; i++){
		printf("名前　%s 日付　%s\n",name[i],date[i]);
	}

	sortScore(name,H_score,date);

  return 0;
}
