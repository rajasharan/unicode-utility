#include <stdio.h>
#include <stdlib.h>
//#include "unicode_util.h"

extern int u_strlen(char *);

int main(void)
{
        char *c = malloc(10);
        fgets(c, 10, stdin);
        
        char *s = c;
        while (s && *s != '\0') {
                printf("%x: %c\n", *s, *s);
                s++;
        }

        printf("strlen: %d\n", u_strlen(c));
        return 0;
}
