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
  puts("<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"></head><body><p><h1><span>S</span><span>T</span><span>A</span><span>G</span><span>E</span><span> ☆</span><span>C</span><span>L</span><span>E</span><span>A</span><span>R</span><span>!</span><span>!</span></h1></p><style>@import url(https://fonts.googleapis.com/css?family=Signika:700,300,600);html, body { height: 100%;}body { display: flex; justify-content: center; align-items: center; margin:20px 0; text-align:center; background:beige; overflow:hidden; }h1 { font-size: 200px; font:bold 7.5vw/1.6 'Signika', sans-serif; user-select:none; padding: 50px; position: relative; top:-150px; left: 150px;}h1 span { display:inline-block; animation:float .2s ease-in-out infinite; } @keyframes float {  0%,100%{ transform:none; }  33%{ transform:translateY(-1px) rotate(-2deg); }  66%{ transform:translateY(1px) rotate(2deg); }}body:hover span { animation:bounce .6s; }@keyframes bounce {  0%,100%{ transform:translate(0); }  25%{ transform:rotateX(20deg) translateY(2px) rotate(-3deg); }  50%{ transform:translateY(-20px) rotate(3deg) scale(1.1);  }}span:nth-child(4n) { color:hsl(50, 75%, 55%); text-shadow:1px 1px hsl(50, 75%, 45%), 2px 2px hsl(50, 45%, 45%), 3px 3px hsl(50, 45%, 45%), 4px 4px hsl(50, 75%, 45%); }span:nth-child(4n-1) { color:hsl(135, 35%, 55%); text-shadow:1px 1px hsl(135, 35%, 45%), 2px 2px hsl(135, 35%, 45%), 3px 3px hsl(135, 35%, 45%), 4px 4px hsl(135, 35%, 45%); }span:nth-child(4n-2) { color:hsl(155, 35%, 60%); text-shadow:1px 1px hsl(155, 25%, 50%), 2px 2px hsl(155, 25%, 50%), 3px 3px hsl(155, 25%, 50%), 4px 4px hsl(140, 25%, 50%); }span:nth-child(4n-3) { color:hsl(30, 65%, 60%); text-shadow:1px 1px hsl(30, 45%, 50%), 2px 2px hsl(30, 45%, 50%), 3px 3px hsl(30, 45%, 50%), 4px 4px hsl(30, 45%, 50%); }h1 span:nth-child(2){ animation-delay:.05s; }h1 span:nth-child(3){ animation-delay:.1s; }h1 span:nth-child(4){ animation-delay:.15s; }h1 span:nth-child(5){ animation-delay:.2s; }h1 span:nth-child(6){ animation-delay:.25s; }h1 span:nth-child(7){ animation-delay:.3s; }h1 span:nth-child(8){ animation-delay:.35s; }h1 span:nth-child(9){ animation-delay:.4s; }h1 span:nth-child(10){ animation-delay:.45s; }h1 span:nth-child(11){ animation-delay:.5s; }h1 span:nth-child(12){ animation-delay:.55s; }h1 span:nth-child(13){ animation-delay:.6s; }h1 span:nth-child(14){ animation-delay:.65s; }</style><div class=\"score\"><p><center><font size=\"7\" color=\"#54917f\">");

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
  puts("</font></center></p></div><!-- hrefのなかみを環境に合わせて変更してえええええええええええええください --><p><span style=\"margin-right:100px\"> <a href=\"#\" class=\"top_btn\">TOP</a></span>");

	puts("<span style=\"margin-left:50px\"><a href=\"all_clear.cgi?");

	fputs(buf, stdout);

	puts("\" class=\"next_btn\">NEXT</a></span></p>");

	

puts("<style>.score{  position: relative;  top: -25px;  right: 450px;}.top_btn{  display: block;  height: 50px;  width: 200px;  position: relative;  top: 300px;  left: -700px;  font-size: 30px;  text-decoration: none;  font-weight: bold;  line-height: 60px;  text-align: center;  color: #5d7731;  border: 1px solid #98b85b;  border-bottom: 1px solid #799545;  text-shadow: 0px 1px 0px #d5e8aa;  -webkit-box-shadow: 1px 1px 0 #cce3a1 inset, 1px 1px 1px #e9e9e9;  -moz-box-shadow: 1px 1px 0 #cce3a1 inset, 1px 1px 1px #e9e9e9;  box-shadow: 1px 1px 0 #cce3a1 inset, 1px 1px 1px #e9e9e9;  background: #cae285;  background: -webkit-gradient(linear, left top, left bottom, color-stop(0.5, #cae285), color-stop(0.5, #a3cd5a));  background: -moz-linear-gradient(top, #cae285 50%,#a3cd5a 50%);  background: -o-linear-gradient(top, #cae285 50%,#a3cd5a 50%);  background: -ms-linear-gradient(top, #cae285 50%,#a3cd5a 50%);  background: linear-gradient(top, #cae285 50%, #a3cd5a 50%);  filter: progid:DXImageTransform.Microsoft.gradient(GradientType=0,startColorstr='#cae285 50%', endColorstr='#a3cd5a 50%');  -ms-filter: \"progid:DXImageTransform.Microsoft.gradient(GradientType=0,startColorstr='#cae285 50%', endColorstr='#a3cd5a 50%')\";}.top_btn:active{  /* クリックした時 */  -ms-transform: translateY(2px);  -webkit-transform: translateY(2px);  transform: translateY(2px);  box-shadow: none;}.next_btn{  display: block;  height: 50px;  width: 200px;  position: relative;  top: 140px;  left: -150px;  text-decoration: none;  font-size: 30px;  font-weight: bold;  line-height: 60px;  text-align: center;  color: #996633;  border: 1px solid #eab551;  border-bottom: 1px solid #b98a37;  text-shadow: 0px 1px 0px #fedd9b;  -webkit-box-shadow: 0 1px 0 #fee9aa inset, 1px 1px 1px #e9e9e9;  -moz-box-shadow: 0 1px 0 #fee9aa inset, 1px 1px 1px #e9e9e9;  box-shadow: 0 1px 0 #fee9aa inset, 1px 1px 1px #e9e9e9;  background: #feda71;  background: -webkit-gradient(linear, left top, left bottom, color-stop(0.5, #feda71), color-stop(0.5, #febe4d));  background: -moz-linear-gradient(top, #feda71 50%,#febe4d 50%);  background: -o-linear-gradient(top, #feda71 50%,#febe4d 50%);  background: -ms-linear-gradient(top, #feda71 50%,#febe4d 50%);  background: linear-gradient(top, #feda71 50%, #febe4d 50%);  filter: progid:DXImageTransform.Microsoft.gradient(GradientType=0,startColorstr='#feda71 50%', endColorstr='#febe4d 50%');  -ms-filter: \"progid:DXImageTransform.Microsoft.gradient(GradientType=0,startColorstr='#feda71 50%', endColorstr='#febe4d 50%')\";}.next_btn:active{  /* クリックした時 */  -ms-transform: translateY(2px);  -webkit-transform: translateY(2px);  transform: translateY(2px);  box-shadow: none;}</style></body></html>");

  free(buf);			/* メモリを解放 */
  
  return 0;
 }
