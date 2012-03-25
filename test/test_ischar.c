#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../unicode_util.h"

int main(void)
{
        char *c = "¢";
        int len = u_ischar(c);
        printf("¢: %d bytes\n", len);
        assert(len == 2);

        c = "ण";
        len = u_ischar(c);
        printf("ण: %d bytes\n", len);
        assert(len == 3);

        c = NULL;
        len = u_ischar(c);
        assert(len == -1);

        c = "";
        len = u_ischar(c);
        assert(len == 1); //because '\0' is a valid utf-8 char

        /* TODO: test non utf-8 character
         * Not working at the moment
        c = 0x11100000;
        len = u_ischar(c);
        assert(len == 0);
        */

        return 0;
}
