#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "unicode_util.h"

int main(void)
{
        char *c = "ahßƒ∫∂lk";
        int len = u_strlen(c);
        printf("ahßƒ∫∂lk: %d bytes\n", len);
        assert(len == 8);
        return 0;
}
