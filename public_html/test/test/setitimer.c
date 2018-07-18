   /*
    * test_getitimer2.c
    * getitimer を使った割り込みのテスト
    * 1998 年 3 月 19 日
    */
 
   #include <stdio.h>
   #include <sys/time.h>
   #include <signal.h>
  #include <unistd.h>

  #define LOOP 10
  #define DELAY_SEC 0
  #define DELAY_USEC 10000

  volatile int count = 0;
  struct timeval tv[LOOP];
  struct timezone tz;

  void sig_action()
  {
    gettimeofday(tv + count, &tz);
    count ++;
  }

  int main()
  {
    struct sigaction act, oldact;
    struct itimerval value, ovalue;
    int i;

  /* 割り込み関数の設定 */
    act.sa_handler = sig_action;
    // act.sa_mask = 0;
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, &oldact);

  /* 割り込みの設定 */
  /*   最初の割り込みは it_value で指定した値 */
  /*   2 度目以降は it_interval で指定した値のようです */
    value.it_value.tv_usec = DELAY_USEC;
    value.it_value.tv_sec = DELAY_SEC;
    value.it_interval.tv_usec = DELAY_USEC;
    value.it_interval.tv_sec = DELAY_SEC;
    setitimer(ITIMER_REAL, &value, &ovalue);

  /* 待ち */
    while(count < LOOP);

  /* 割り込みの解除 */
    setitimer(ITIMER_REAL, &ovalue, &value);

  /* 割り込み関数の解除 */
   sigaction(SIGALRM, &oldact, NULL);

  /* 結果の表示 */
    for(i=0; i<LOOP; i++){
      printf("%3d : %ld:%06ld\n", i, tv[i].tv_sec, tv[i].tv_usec);
    }

  /* 終了 */
    return 0;
  }