#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main() {
    int buffer_size = 256;
    char * string = (char*) malloc(buffer_size* sizeof(char));
    read(1,string,(size_t) 256);

    char delimiter = ' ';
    //get the first number
    char * a = strsep(&string,&delimiter);
    int  achars =(int)strlen(a);

    //get the second number and but first remove the trailing nl
    char * b = string;
    b[strcspn(b, "\n")] = 0;
    int  bchars =(int)strlen(b);

    printf("first number %s  and it has %d digits,"
           " second number %s and has %d digits\n"
            ,a,achars,b,bchars);
    return 0;
}