#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

/* ユーザ定義関数の宣言 */
void SetSignal(int SignalName);
void SigHandler(int SignalName);
void Input(void);

int main(void)
{
  SetSignal(SIGINT);

  Input();

  return 0;
}

void Input(void)
{
  while(1) {
    printf("実行中!!\n");
    sleep(3);
  }

  return;
}

/* シグナルの設定 */
void SetSignal(int p_signame)
{
  if (signal(p_signame,SigHandler) == SIG_ERR) {
    /* シグナル設定エラー  */
    printf("シグナルの設定が出来ませんでした。終了します\n");
    exit(1);
  }

  return;
}

/* シグナル受信/処理 */
void SigHandler(int p_signame)
{
  static int sig_cnt = 0;

  ++sig_cnt;
  if (sig_cnt <= 2) {
    printf("%d回目の割り込みです。無視します\n", sig_cnt);
  }
  else {
    printf("%d回目の割り込みです。終了します\n", sig_cnt);
    exit(0);
  }

  /* シグナルの再設定 */
  SetSignal(p_signame);

  return;
}