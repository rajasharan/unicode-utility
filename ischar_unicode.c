#include "unicode_util.h"

/* return: number of bytes of the first utf-8 char starting at c
 * 0: not a utf-8 char
 */
int u_ischar(char *c)
{
        char u[7];
        u[0] = 0x80; /* 0b10000000; secondary byte */

        u[1] = 0x00; /* 0b00000000; 1 byte len */
        u[2] = 0xc0; /* 0b11000000; 2 byte len */
        u[3] = 0xe0; /* 0b11100000; 3 byte len */
        u[4] = 0xf0; /* 0b11110000; 4 byte len */
        u[5] = 0xf8; /* 0b11111000; 5 byte len */
        u[6] = 0xfc; /* 0b11111100; 6 byte len */

        char *s = c;
        int i, j=1, utf=0;
        for (i=1; i<7; i++) {
                if (*s & u[i] == u[i]) {
                        s++;
                        utf = 1;
                        while (j<i) {
                                if (*s & u[0] == u[0]) {
                                        s++;
                                        j++;
                                }
                                else {
                                        utf = 0;
                                        break;
                                }
                        }
                        break;
                }
        }
        if (utf)
                return i;

        return 0;
}
