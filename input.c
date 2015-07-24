#include <stdlib.h>
#include <stdio.h>

#include <assert.h>

#include "input.h"

double carry_in(void)
{
    char * text;
    register double result;

    text = scan_keys();
    result = strtod(text, NULL);
    return (result);
}

long scan_long(void)
{
    char * text;
    register long result;

    text = scan_keys();
    result = strtol(text, NULL, 0);
    return (result);
}

unsigned long scan_unsigned(void)
{
    char * text;
    register unsigned long result;

    text = scan_keys();
    result = strtoul(text, NULL, 0);
    return (result);
}

char * scan_keys(void)
{
    static char pre_buffer[256];
    register size_t i;
    int character;

    for (i = 0; i < sizeof(pre_buffer); i++) {
        character = getchar();
        if (character == '\n')
            break;
        assert(character != EOF);
        pre_buffer[i] = (char)character;
    }

    assert(i < sizeof(pre_buffer));
    pre_buffer[i] = '\0';
    return &(pre_buffer[0]);
}
