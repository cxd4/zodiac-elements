#include <math.h>
#include "geometry.h"

#include <GL/gl.h>

static GLdouble vertices[POLYGON_DEPTH][NUMBER_OF_COORDINATES];

static const GLfloat colors[NUMBER_OF_ELEMENTS + 3][NUMBER_OF_COMPONENTS] = {
    { 0, 0, 1, OPACITY, }, /* "Black Tortoise" (water, north) */
    { 1, 1, 1, OPACITY, }, /* "White Tiger" (metal, west) */
    { 1, 1, 0, OPACITY, }, /* "Yellow Dragon" (earth, center) */
    { 1, 0, 0, OPACITY, }, /* "Vermillion Bird" (fire, south) */
    { 0, 1, 0, OPACITY, }, /* "Green Dragon" (wood, east) */

    { 1/2.F, 0, 1/2.F, OPACITY }, /* "Purple Emperor" (X is controlled by Y.) */
    { 1, 0, 1, OPACITY, }, /* magenta (X controls Y.) */

    { 1, 1, 1, 1 }, /* system default to the OpenGL state machine */
};

GLvoid init_GL_state(void)
{
    double distance_between_polygon_and_screen_boundary;
    register size_t vertex_ID;

    for (vertex_ID = 0; vertex_ID < POLYGON_DEPTH; vertex_ID++) {
        vertices[vertex_ID][X] = cosd(ROTATION + INTERVAL*vertex_ID);
        vertices[vertex_ID][Y] = sind(ROTATION + INTERVAL*vertex_ID);
        vertices[vertex_ID][Z] = PLANE_Z;
        vertices[vertex_ID][W] = 1.0 / RADIUS;
    }

/*
 * Now drop the pentagon lower, slightly, to vertically center it on the
 * screen and minimize the chance of rendering outside the OpenGL canvas.
 */
    distance_between_polygon_and_screen_boundary = 1 + vertices[FIRE][Y];
    for (vertex_ID = 0; vertex_ID < POLYGON_DEPTH; vertex_ID++)
        vertices[vertex_ID][Y] -=
            distance_between_polygon_and_screen_boundary
          / 2
        ;

    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glVertexPointer(NUMBER_OF_COORDINATES, GL_DOUBLE, 0, vertices);
    glColorPointer(NUMBER_OF_COMPONENTS, GL_FLOAT, 0, colors);

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
    glColor4fv(colors[NUMBER_OF_ELEMENTS + 2]);

    glDisableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_LINE_LOOP, 0, POLYGON_DEPTH);

    glBegin(GL_LINE_STRIP);
    glColor4fv(colors[NUMBER_OF_ELEMENTS + 0]);
    switch (final_element) {
    case WATER:
        glVertex4dv(vertices[EARTH_VERTEX]);
        glColor4fv(colors[WATER_VERTEX]);
        glVertex4dv(vertices[WATER_VERTEX]);
        glColor4fv(colors[NUMBER_OF_ELEMENTS + 1]);
        glVertex4dv(vertices[FIRE_VERTEX]);
        break; /* Earth controls Water; Water controls Fire. */
    case FIRE:
        glVertex4dv(vertices[WATER_VERTEX]);
        glColor4fv(colors[FIRE_VERTEX]);
        glVertex4dv(vertices[FIRE_VERTEX]);
        glColor4fv(colors[NUMBER_OF_ELEMENTS + 1]);
        glVertex4dv(vertices[METAL_VERTEX]);
        break; /* Water controls Fire; Fire controls Metal. */
    case METAL:
        glVertex4dv(vertices[FIRE_VERTEX]);
        glColor4fv(colors[METAL_VERTEX]);
        glVertex4dv(vertices[METAL_VERTEX]);
        glColor4fv(colors[NUMBER_OF_ELEMENTS + 1]);
        glVertex4dv(vertices[WOOD_VERTEX]);
        break; /* Fire controls Metal; Metal controls Wood. */
    case WOOD:
        glVertex4dv(vertices[METAL_VERTEX]);
        glColor4fv(colors[WOOD_VERTEX]);
        glVertex4dv(vertices[WOOD_VERTEX]);
        glColor4fv(colors[NUMBER_OF_ELEMENTS + 1]);
        glVertex4dv(vertices[EARTH_VERTEX]);
        break; /* Metal controls Wood; Wood controls Earth. */
    default:
        glVertex4dv(vertices[WOOD_VERTEX]);
        glColor4fv(colors[EARTH_VERTEX]);
        glVertex4dv(vertices[EARTH_VERTEX]);
        glColor4fv(colors[NUMBER_OF_ELEMENTS + 1]);
        glVertex4dv(vertices[WATER_VERTEX]);
    }
    glEnd();

    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_POINTS, 0, POLYGON_DEPTH);

    glDisableClientState(GL_VERTEX_ARRAY);
    glFlush();
    glFinish();
    return;
}

void reshape(GLsizei width, GLsizei height)
{
    static GLint viewport[4];
    GLfloat point_size_limits[2];
    GLfloat point_size;
    GLsizei new_size;

/*
 * Force square screen dimensions only, as window sizes amounting to a
 * non-square render viewport will make the pentagon disproportionate.
 */
    new_size = (width < height) ? width : height;

    glGetFloatv(
        GL_POINT_SIZE_RANGE,
        &point_size_limits[0]
    );
    point_size = new_size / 25.f;
    if (point_size < point_size_limits[0])
        point_size = point_size_limits[0];
    if (point_size > point_size_limits[1])
        point_size = point_size_limits[1];
    glPointSize(point_size);

    glGetIntegerv(
        GL_VIEWPORT,
        &viewport[0]
    );
    glViewport(viewport[0], viewport[1], new_size, new_size);
    return;
}
