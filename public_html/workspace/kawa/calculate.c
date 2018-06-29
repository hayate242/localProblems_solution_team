#include <stdio.h>
int main()
{
  int x[100];
  int i,N,max,min,sum=0 ;
  double ave;
  printf("Enter a number of data(N)\n");
  scanf("%d",&N);
  printf("Enter datas of integer\n");
  for (i=0; i<N; i++)
   {
     scanf("%d", &x[i]);
     sum += x[i];
   }
  ave = (double)sum/N;
  max = x[0];
  min= x[0];
  for(i=0; i<N; i++){
    if (max < x[i])
      {
	max = x[i];
    }
    if (min > x[i])
      {
	min = x[i];
	}
  }
  printf("Maximum = %d\n", max);
  printf("Minimum = %d\n", min);
  printf("Average = %.1f\n", ave);
  return 0;
}
