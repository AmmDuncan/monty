#include "monty.h"

/**
 * strsep - separate string on a delimeter
 * @stringp - pointer to string
 * @delim - string to delimit by
 * Return: string
 */
char *strsep(char **stringp, const char *delim) {
    char *rv = *stringp;
    if (rv) {
        *stringp += strcspn(*stringp, delim);
        if (**stringp)
            *(*stringp)++ = '\0';
        else
            *stringp = 0; }
    return rv;
}

