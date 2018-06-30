#include<stdio.h>
#include<string.h>

int main(void){
  float foodcost = 0;
  float income = 0;
  float result = 0;
  
  //char input[256];
  //char s[]=" ";
  //char *tok;
  
  scanf("%f%f",&foodcost,&income);
  printf("%f %f\n",foodcost,income);
  
  result = foodcost/income*100.0;

  printf("Engel's coefficent = %f\n",result);
  

  return 0;
}
