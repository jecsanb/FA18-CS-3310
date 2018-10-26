#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <tgmath.h>

int chartoint(char c){
    return  c & 0x0F;
}
// turns a null terminated string to its int value
int strtoint(char * str){
    assert(str != NULL);
    int digits =(int)strlen(str);
    int result = 0;
    int magnitude = 1;
    for(int i = digits - 1; i >= 0; --i){
          result += chartoint(str[i])*magnitude;
          magnitude *= 10;
    };
    return result;
}

int main() {
    int buffer_size = 256;
    char *string = (char *) malloc(buffer_size * sizeof(char));
    read(1, string, (size_t) 256);

    char delimiter = ' ';
    //get the first number
    char *a = strsep(&string, &delimiter);
    //get the size
    int achars = (int) strlen(a);

    //get the second number
    char *b = string;
    //remove the nl
    b[strcspn(b, "\n")] = 0;
    //get the size
    int bchars = (int) strlen(b);

   // printf("A:%s size=%d,"
   // "B:%s size=%d\n", a, achars, b, bchars);
   // printf("valueA is: %d\n",strtoint(a));
   // printf("valueB is: %d\n",strtoint(b));

    return 0;
}