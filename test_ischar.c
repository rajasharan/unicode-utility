#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "unicode_util.h"

int main(void)
{
        char *c = "¢";
        int len = u_ischar(c);
        printf("char size: %d bytes\n", len);
        assert(len == 2);
        return 0;
}
