#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* bzero */

#include <sys/types.h> /* netinet/in.h */
#include <sys/socket.h> /* AF_INET */
#include <netinet/in.h> /* sockaddr_in */
#include <netdb.h> /* gethostbyname */
#include <sys/uio.h>
#include <sys/param.h>
#include <unistd.h>
#include <time.h>

#define  DESTSERV "192.168.29.7"
#define  DESTPORT 2000
// #define  MESSAGE  "GET / HTTP/1.0\r\nHOST: 192.168.29.7\r\n\r\n"
#define  MESSAGE  ":MAIN:DATA?\r\n" //最新の測定データを呼ぶ
// #define  MESSAGE  ":MAIN:FUNC 0\r\n"
#define  BUF_LEN  1024

int main() {

    struct hostent *hostent;
    struct sockaddr_in server;

    int fd;
    int portNUM = 0;
    int serverWroteByte;
    char buf[BUF_LEN]; /* receive buffer */

    //csv file write setteings
    FILE *fp;
    char *fname = "20180628.csv";
//   time variables
    time_t timer;
    struct tm *local;


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
    // making socket
    if ( ( fd = socket(AF_INET, SOCK_STREAM, 0) ) < 0) {
        fprintf(stderr, "Cannot make socket.\n");
        return 0;
    }
    // connection start
    printf("connection started\n");
    if ( connect(fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Cannot connect.\n");
        return 0;
    }else {
        printf("Connection Established! connected port = %d\n", DESTPORT);
    }

    /* Receive data */
    while (1) {   
        
        // file open
        fp = fopen( fname, "a" );
        if( fp == NULL ){
          printf( "%sファイルが開けません¥n", fname );
          return -1;
        }
        /* 現在時刻を取得 */
        timer = time(NULL);
        local = localtime(&timer); /* 地方時に変換 */

        
        serverWroteByte = write(fd, MESSAGE, strlen(MESSAGE));
        // printf("wrote to server %d bytes\n", serverWroteByte);
        read(fd, buf, BUF_LEN);
        printf("%2d:%2d:%2d,%s", local->tm_hour, local->tm_min, local->tm_sec, buf);
     
        fprintf( fp, "%2d:%2d:%2d,%s", local->tm_hour, local->tm_min, local->tm_sec, buf);
        // fprintf( fp, "%s\n", "aaaaaaa");
        sleep(1);
        fclose( fp );
        // printf( "%sファイル書き込みが終わりました¥n", fname );
    }
    close(fd);
    return 0;
}