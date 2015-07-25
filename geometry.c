#include <math.h>
#include "geometry.h"

#include <GL/gl.h>

static GLdouble vertices[POLYGON_DEPTH][NUMBER_OF_COORDINATES];

static const GLfloat colors[NUMBER_OF_ELEMENTS][NUMBER_OF_COMPONENTS] = {
    { 1, 1, 0, OPACITY, }, /* "Yellow Dragon" (earth, center) */
    { 0, 0, 1, OPACITY, }, /* "Black Tortoise" (water, north) */
    { 1, 0, 0, OPACITY, }, /* "Vermillion Bird" (fire, south) */
    { 1, 1, 1, OPACITY, }, /* "White Tiger" (metal, west) */
    { 0, 1, 0, OPACITY, }, /* "Green Dragon" (wood, east) */
};

GLvoid init_GL_state(void)
{
    register size_t vertex_ID;

    for (vertex_ID = 0; vertex_ID < POLYGON_DEPTH; vertex_ID++) {
        vertices[vertex_ID][X] = cosd(ROTATION + INTERVAL*vertex_ID);
        vertices[vertex_ID][Y] = sind(ROTATION + INTERVAL*vertex_ID);
        vertices[vertex_ID][Z] = PLANE_Z;
        vertices[vertex_ID][W] = 1.0 / RADIUS;
    }

    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    glVertexPointer(NUMBER_OF_COORDINATES, GL_DOUBLE, 0, vertices);
    glColorPointer(NUMBER_OF_COMPONENTS, GL_FLOAT, 0, colors);

    glPointSize(16);
    glAlphaFunc(GL_NOTEQUAL, 0);
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
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor4f(1, 1, 1, 1);

    glDisableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_LINE_LOOP, 0, POLYGON_DEPTH);

    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_POINTS, 0, POLYGON_DEPTH);

    glDisableClientState(GL_VERTEX_ARRAY);
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
