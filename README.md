Unicode (UTF-8) utility functions
=================================

```C
/* return: length of string utf */
int u_strlen(char *utf);
```

```C
/* 
 * return: number of bytes of first character starting at utf
 * 0: if not a utf character code
 * -1: if null character
 */
int u_ischar(char *utf);
```

Run tests
---------

    make test
