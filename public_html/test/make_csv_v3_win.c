#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* bzero */

#include <sys/types.h> /* netinet/in.h */
#include <Winsock2.h> /* AF_INET */
#include <Windows.h>
#include <process.h>
// #include <netinet/in.h> /* sockaddr_in */
// #include <netdb.h> /* gethostbyname */
// #include <sys/uio.h>
#include <sys/param.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>


#define  DESTSERV "192.168.29.7"
#define  DESTPORT 2000
// #define  MESSAGE  "GET / HTTP/1.0\r\nHOST: 192.168.29.7\r\n\r\n"
#define  MESSAGE  ":MAIN:DATA?\r\n" //最新の測定データを呼ぶ
#define  BUF_LEN  1024
#define DELAY_SEC 1

struct hostent *hostent;
struct sockaddr_in server;

int fd;
int portNUM = 0;
int serverWroteByte;
char buf[BUF_LEN]; /* receive buffer */
int readLen;

//csv file write setteings
FILE *fp;
char fname[256];
//   time variables
time_t timer;
struct tm *local;
char year[4];
char month[2];
char date[2];
char *month0;
char csv[4] = ".csv";

void save_data(int);

int main() {
    // struct itimerval it;
    // it.it_interval.tv_sec = DELAY_SEC;         // タイマーインターバルの設定
    // it.it_interval.tv_usec = 0;
    // it.it_value.tv_sec = DELAY_SEC;
    // it.it_value.tv_usec = 0;
    

    hostent = gethostbyname(DESTSERV); /* lookup IP */
    printf("%s\n", hostent->h_name);
    if (hostent == NULL ) {
        fprintf(stderr, "Cannot resolve %s.\n", DESTSERV);
        return 0;
    }

    bzero(&server, sizeof(server)); /* zero clear struct */

    server.sin_family = AF_INET;
    /* server.sin_addr = hostent->h_addr */
    bcopy(hostent->h_addr, &server.sin_addr, hostent->h_length);

    server.sin_port = htons(DESTPORT);

    // /* Set handler to SIGALRM */
    // if (SIG_ERR == signal(SIGALRM, save_data)) {
    //     printf("failed to set signal handler.\n");
    // }

    // setitimer(ITIMER_REAL, &it, 0); 
    // while(1){
    //     pause();
    // } 
    save_data(12);
    return 0;
}

void save_data(int sig) {
    char *time_format;

    // making socket
    if ( ( fd = socket(AF_INET, SOCK_STREAM, 0) ) < 0) {
        fprintf(stderr, "Cannot make socket.\n");
        exit(1);
    }
    // connection start
    printf("connection started\n");
    if ( connect(fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Cannot connect.\n");
        exit(1);
    }else {
        printf("Connection Established! connected port = %d\n", DESTPORT);
    }
    /* 現在時刻を取得 */
    timer = time(NULL);
    local = localtime(&timer); /* 地方時に変換 */
    // fname　を日付ごとに変える
    strftime(fname, 18, "data/%Y%m%d.csv", local);
    printf("%s\n", fname);
    // file open
    fp = fopen( fname, "a" );
    if( fp == NULL ){
        printf( "%sファイルが開けません\n", fname );
        exit(1);
    }

    
    serverWroteByte = write(fd, MESSAGE, strlen(MESSAGE));
    // printf("wrote to server %d bytes\n", serverWroteByte);
    readLen = read(fd, buf, BUF_LEN);
    // bufの最後にに¥0を入れる，readの戻り値は受け取った文字の数<-利用する
    buf[readLen] = '\0';
    printf("%2d:%2d:%2d,%s", local->tm_hour, local->tm_min, local->tm_sec, buf);
    fprintf( fp, "%2d:%2d:%2d,%s", local->tm_hour, local->tm_min, local->tm_sec, buf);
    fclose( fp );
    shutdown(fd, 2);
    close(fd);
}
