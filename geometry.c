#include "geometry.h"

#include <GL/gl.h>

GLvoid init_GL_state(void)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(
        0.f / 100, /* 0% red */
        0.f / 100, /* 0% green */
        0.f / 100, /* 0% blue */
        0.f / 100  /* I prefer a transparent window canvas, when supported. */
    );
    return;
}

void display(void)
{
    glClear(
        GL_COLOR_BUFFER_BIT
      | GL_STENCIL_BUFFER_BIT
    );

    glFlush();
    glFinish();
    return;
}

void reshape(GLint width, GLint height)
{
/*
 * haven't yet implemented window resizing of the picture image
 */
    return;
}
