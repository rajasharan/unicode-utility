#include "unicode_util.h"

/* return: unicode (utf-8) strlen */ 
int u_strlen(char *c)
{
        if (!c || c == '\0')
                return 0;

        int l, len=0;
        while (c != '\0') {
                l = u_ischar(c);
                if (!l) {
                        /* not utf-8 character
                         * should not have reached here
                         * but increamenting c anyway
                         */
                        c++;
                } else {
                        c += l;
                }
                len++;
        }
        return len;
}
