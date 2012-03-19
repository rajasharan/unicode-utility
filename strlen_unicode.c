#include "unicode_util.h"

/* return: unicode (utf-8) strlen */ 
int u_strlen(char *c)
{
        if (!c || c == '\0')
                return 0;

        int l, len=0;
        while (c != '\0') {
                l = u_ischar(c);
                if (l == 0) {
                        /* not utf-8 character
                         * should not have reached here
                         * but incrementing c anyway
                         */
                        c++;
                        /* possible cases why we reached here:
                         * 1. genuinely not a utf-8, so incrementing won't hurt
                         * 2. character terminated in the middle of code-point,
                         *    this is a bug, just incrementing won't solve it,
                         *    we need to know how many bytes to increment (TODO)
                         */
                }
                else if (l < 0) {
                        break;
                }
                else {
                        c += l;
                }
                len++;
        }
        return len;
}
