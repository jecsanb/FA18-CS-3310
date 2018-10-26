#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <math.h>

//returns the number of digits in n
int countDigit(int n);

int chartoint(char c);

int strtoint(char *str);
void printstr(char *str);

void printstr(char *str){
    assert( str != NULL);
    while(*str){
        putchar(*str);
        ++str;
    }
}
int countDigit(int n) {
    n = abs(n);
    return (int) (floor(log10(n))) + 1;
}

char  inttochar(int n) {
    assert(n < 10);
    return (char) (n + 0x30);

}

char *inttostr(int num) {
    int digits = countDigit(num) + 1;
    char *string = malloc((digits) * sizeof(char));
    int v = 0;
    for (int i = digits-2; i >= 0; --i) {
        v = num % 10;
        string[i] = inttochar(v);
        num /= 10;
    }
    string[digits -1 ] = 0;
    return string;
}

//turns a char to its integer representation
int chartoint(char c) {
    return c & 0x0F;
}

// turns a null terminated string to its integer representation
//e.g "12" -> 12 where typeof(12) = int
int strtoint(char *str) {
    assert(str != NULL);
    int digits = (int) strlen(str);
    int result = 0;
    int magnitude = 1;
    for (int i = digits - 1; i >= 0; --i) {
        result += chartoint(str[i]) * magnitude;
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
    //get the second number
    char *b = string;
    //remove the nl
    b[strcspn(b, "\n")] = 0;

    // printf("A:%s size=%d,"
    // "B:%s size=%d\n", a, achars, b, bchars);
    // printf("valueA is: %d\n",strtoint(a));
    // printf("valueB is: %d\n",strtoint(b));
    int result = strtoint(a) * strtoint(b);
    char *strresult = inttostr(result);
    printstr(strresult);
    return 0;
}