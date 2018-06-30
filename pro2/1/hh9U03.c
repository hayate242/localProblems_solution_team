#include<stdio.h>
#include<string.h>

int strReplacer(char *src, char *before, char *after){
  char *p = NULL;
  int i = 0;
  
  if(strlen(before) != strlen(after)){ return -1;}

  return 1;
}

int main(){
  char input[256];
  int flag = 0;

  scanf("%s",&input);
  printf("%s\n",input);
  
  flag = strReplacer(input,"e","u");
  return 0;
}
