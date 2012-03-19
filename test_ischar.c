#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "unicode_util.h"

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
        return 0;
}
