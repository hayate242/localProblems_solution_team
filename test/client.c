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

#define  DESTSERV "192.168.29.7"
#define  DESTPORT 2000
// #define  MESSAGE  "GET / HTTP/1.0\r\nHOST: 192.168.29.7\r\n\r\n"
#define  MESSAGE  ":MAIN:DATA? 4\r\n" //最新の測定データを呼ぶ
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
    fp = fopen( fname, "a" );
    if( fp == NULL ){
        printf( "%sファイルが開けません¥n", fname );
        return -1;
    }
    // fprintf( fp, "%s\n",    "DCV_,ND_,___,9.91E+37,0" );

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
    printf("connection started\n");
    if ( ( fd = socket(AF_INET, SOCK_STREAM, 0) ) < 0) {
        fprintf(stderr, "Cannot make socket.\n");
        return 0;
    }
    if ( connect(fd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "Cannot connect.\n");
        return 0;
    }else {
        printf("Connection Established! connected port = %d\n", DESTPORT);
    }

    /* Receive data */
    while (1) {    
        serverWroteByte = write(fd, MESSAGE, strlen(MESSAGE));
        // printf("wrote to server %d bytes\n", serverWroteByte);
        read(fd, buf, BUF_LEN);
        printf("%s", buf);
        // printf( "%sファイル書き込みが終わりました¥n", fname );
        // fprintf( fp, "%s", buf);
        fprintf( fp, "%s\n",    "DCV_,ND_,___,9.91E+37,0" );
        // printf( "%sファイル書き込みが終わりました¥n", fname );
        sleep(1);
        // close(fd);
    }
    close(fd);
    fclose(fp);
    return 0;
}