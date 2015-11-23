#include <stdlib.h>
#include <stdio.h>

#include <assert.h>
#include <malloc.h>

#include "input.h"

void key_press(int key, int x, int y)
{
    static GLsizei viewport[4];
    FILE * stream;
    void * pixels;

    switch (key) {
    case GLUT_KEY_F3:
        glGetIntegerv(GL_VIEWPORT, &viewport[0]);
        pixels = malloc(4 * viewport[2] * viewport[3]);
        glReadPixels(
            x = 0, /* unused */
            y = 0, /* unused */
            viewport[2],
            viewport[3],
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            pixels
        );
        stream = fopen("r8g8b8a8.data", "wb");
        fwrite(pixels, 4 * viewport[2], viewport[3], stream);
        fclose(stream);
        free(pixels);
        break;
    }
    glutPostRedisplay();
    return;
}

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
