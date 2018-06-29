/* フォームデータをたんに出力するプログラム */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define HTML_HEADER(CHAR_SET) \
  "Content-type: text/html; charset=" CHAR_SET "\n\n"

int main(void)
{
  int data_size;		/* フォームデータのデータサイズ */
  char *buf = NULL;	      /* フォームデータを保持しておくところ */
  char *cp;

  puts(HTML_HEADER("UTF-8")); /* Web ページの文字コードは UTF-8 が一般的 */
  puts("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"></head><body><style>body {  margin: 20px 0;  text-align: center;  top: 100px;  right: 50px;  left: 0px;  bottom: 0px;  /* 画像ファイルの指定 */  background-image: url(all.jpg);     /* 画像を常に天地左右の中央に配置 */  background-position: center center;     /* 画像をタイル状に繰り返し表示しない */  background-repeat: no-repeat;     /* コンテンツの高さが画像の高さより大きい時、動かないように固定 */  background-attachment: fixed;     /* 表示するコンテナの大きさに基づいて、背景画像を調整 */  background-size: cover;   }</style><section class=\"container\">  <p><h1 class=\"title\">    <span>ALL&nbsp;STAGE</span>    <span>CLEAR<font color=\"ff0000\">&#9829;</font></span>  </h1></section></p><style>@import 'https://fonts.googleapis.com/css?family=Baloo+Paaji';$primary-color: #1e90ff ;$secondary-color: #ffe221;$tertiary-color: #ffffff;  html, body{  height: 100%;}body{  font-family: 'Baloo Paaji', cursive;  background: $primary-color;  display: flex;  justify-content: center;  align-items: center;  text-allign: center; }.container{  width: 400px;  height: 220px;}h1{  font-size: 100px;  padding: 50px;  text-transform: uppercase;  color: #110000;  position: relative;  top: -175px;      span{    width: 100%;    float: left;    color: $tertiary-color;    -webkit-clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 80%);    clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 80%);    transform: translateY(-50px);    opacity: 0;    animation-name: titleAnimation;    animation-timing-function:ease;    animation-duration: 3s;  }}h1 span{  animation-delay: 0.6s;  -webkit-animation-fill-mode: forwards;  &:first-child{    animation-delay: 0.7s;  }  &:last-child{    color: $secondary-color;    animation-delay: 0.5s;  }}@keyframes titleAnimation {    0% {      transform: translateY(-50px);      opacity: 0;      -webkit-clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 80%);      clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 80%);  }  20% {      transform: translateY(0);      opacity: 1;      -webkit-clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 15%);      clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 15%);  }  80% {       transform: translateY(0);       opacity: 1;      -webkit-clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 15%);      clip-path: polygon(100% 0, 100% 100%, 0 100%, 0 15%);  }  100% {       transform: translateY(50px);       opacity: 0;      -webkit-clip-path: polygon(100% 0, 100% -0%, 0 100%, 0 100%);      clip-path: polygon(100% 0, 100% -0%, 0 100%, 0 100%);      }}</style><div class=\"score\"><p><center><font size=\"7\" >");

  /* 送信方法は POST ．標準入力から読み取る */
  if ((cp = getenv("REQUEST_METHOD")) && (! strcmp(cp, "POST"))) {
    cp = getenv("CONTENT_LENGTH"); /* データサイズを取得 */
    assert(cp);
    data_size = atoi(cp);	/* 数字を，数値へ変換 */
    buf = (char*)malloc(data_size + 1); /* メモリを確保．\0 用に +1 */
    cp = fgets(buf, data_size + 1, stdin); /* データを取得 */
    buf[data_size] = '\0';
  } else if (cp && (! strcmp(cp, "GET"))) {
    /* 送信方法は GET ．環境変数から読み取る */
    cp = getenv("QUERY_STRING");
    assert(cp);
    data_size = strlen(cp);	/* サイズを取得 */
    buf = (char*)malloc(data_size + 1); /* メモリを確保．\0 用に +1 */
    memcpy(buf, cp, data_size + 1); /* データを取得 */
  } else {
    fprintf(stderr, "invalid method: %s\n", cp);
    exit(EXIT_FAILURE);
  }

  /* フォームデータを処理．今回はそのまま出力 */
  fputs(buf, stdout);
	
// hrefのなかみを環境に合わせて変更してえええええええええええええください
  puts("</font></center></p></div><p><!-- hrefのなかみを環境に合わせて変更してえええええええええええええください --><a href=\"#\" class=\"top\">TOP</a>");

	puts("<a href=\"inputName.cgi?");

	fputs(buf, stdout);

	puts("\" class=\"rnk\">RANKING</a></p>");

	

puts("<style>.score{  position: relative;  top: 270px;  right: 300px;}.top{  display: inline-block;  text-decoration: none;  color: #ffffff;  position: relative;  top: 370px;  left: 200px;  width: 100px;  height: 100px;  line-height: 100px;  border-radius: 50%;  border: double 4px #ffffff;  text-align: center;  vertical-align: middle;  overflow: hidden;  transition: .6s;}.top:hover{  -webkit-transform: rotateY(360deg);  -ms-transform: rotateY(360deg);  transform: rotateY(360deg);}.rnk{  display: inline-block;  text-decoration: none;  color: #ff9977;  position: relative;  top: 370px;  left: -50px;  width: 100px;  height: 100px;  line-height: 100px;  border-radius: 50%;  border: double 4px #ff9977;  text-align: center;  vertical-align: middle;  overflow: hidden;  transition: .6s;}.rnk:hover{  -webkit-transform: rotateY(360deg);  -ms-transform: rotateY(360deg);  transform: rotateY(360deg);}</style></body></html>");

  free(buf);			/* メモリを解放 */
  
  return 0;
 }
