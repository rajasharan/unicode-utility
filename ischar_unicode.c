#include "unicode_util.h"

/* return: number of bytes of the first utf-8 char starting at c
 * 0: not a utf-8 char
 */
int u_ischar(char *c)
{
        char u[7];
        u[0] = 0x80; /* 0b10XXXXXX; secondary byte */

        u[1] = 0x00; /* 0b0XXXXXXX; 1 byte len */
        u[2] = 0xc0; /* 0b110XXXXX; 2 byte len */
        u[3] = 0xe0; /* 0b1110XXXX; 3 byte len */
        u[4] = 0xf0; /* 0b11110XXX; 4 byte len */
        u[5] = 0xf8; /* 0b111110XX; 5 byte len */
        u[6] = 0xfc; /* 0b1111110X; 6 byte len */

        /* mask bits */
        char m[7];
        m[0] = 0xc0; /* 0b11000000; */

        m[1] = 0x80; /* 0b10000000; */
        m[2] = 0xe0; /* 0b11100000; */
        m[3] = 0xf0; /* 0b11110000; */
        m[4] = 0xf8; /* 0b11111000; */
        m[5] = 0xfc; /* 0b11111100; */
        m[6] = 0xfe; /* 0b11111110; */

        char *s = c;
        int i, j=1, utf=0;
        for (i=1; i<7; i++) {
                if (((*s & m[i])^u[i]) == 0x00) {
                        s++;
                        utf = 1;
                        while (j<i) {
                                if (((*s & m[0])^u[0]) == 0x00) {
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
