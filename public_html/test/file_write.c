#include <stdio.h>
#include <unistd.h>

int main(void)
{
  FILE *fp;
  char *fname = "comma.csv";
  char *s1 = "test01";
  char *s2 = "test02";
  char *s3 = "test03";
  int n1 = 10;
  int n2 = 20;
  int n3 = 30;
  float f1 = 1.0;
  float f2 = 2.0;
  float f3 = 3.0;
  int i;

  // fp = fopen( fname, "a" );
  // if( fp == NULL ){
  //   printf( "%sファイルが開けません¥n", fname );
  //   return -1;
  // }

    for( i = 0; i < 10; i++ ){
       fp = fopen( fname, "a" );
        if( fp == NULL ){
          printf( "%sファイルが開けません¥n", fname );
          return -1;
        }
        // fprintf( fp, "%s,%d,%d,%f,%f¥n", s1, n1, n1+1, f1, f1+0.1 );
        // fprintf( fp, "%s,%d,%d,%f,%f¥n", s2, n2, n2+1, f2, f2+0.1 );
        fprintf( fp, "%s,%d,%d,%f,%f\n",    s3, n3, n3+1, f3, f3+0.1 );
        sleep(1);
        fclose( fp );

        printf( "%sファイル書き込みが終わりました¥n", fname );  
    }
  return 0;
}