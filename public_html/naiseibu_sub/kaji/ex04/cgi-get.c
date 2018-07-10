#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

  if(getenv(REQUEST_METHOD) == NULL){
    printf("terminal");
    return 0;
  }
  else{
    printf("content-type:text/html\n\n");

    if(strcmp(REQUEST_METHOD,GET) == 0){
      printf("%s",QUERY_STRING);
      return 0;
    }
    else{
      printf("oops");
      return 1;
    }
  }
}
