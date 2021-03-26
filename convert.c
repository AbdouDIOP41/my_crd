#include "convert.h"
#include "my_print.h"

int isNumber(char *str){
    int i = 0;
    int n;
    while(str[i] != '\0'){
        n =  str[i] - '0';
        if ( n < 0 || n > 9)
            return 0;
        i++;
    }
    return 1;
}

int convert_char_to_int(char *str){
    int i = 0 ;
    int n = 0;
    int mult = 1;
    int a ;
    while (str[i] != '\0'){
        i++;
    }
    i--;
    while (i >= 0){
        a = str[i] - '0';
        n = n +  a * mult;
        mult *=10;
        i--;
    }
    return n;
}

void convert_int_to_char( int x){
    if (x < 0){
        my_putchar('-');
        x = -x;
    }
    my_putchar(x + 48);
    //my_putchar('\n');
}
