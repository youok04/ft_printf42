#include "printf.h"

size_t  ft_strlen (char * st)
{
    size_t  i;

    i = 0;
    while (st[i] != '\0')
    {
        i++;
    }
    return(i);
}
