#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

/*
 * header file for the construction of a regular pentagon
 * pointing upwards
 *
 * A regular polygon has 5 interior angles.
 * Each of the 5 angles are congruent and exactly 108 degrees.
 *
 *          Water
 *           / \
 *         /     \
 *       /         \
 * Metal \         / Wood
 *        \       /
 *         \_____/
 *     Earth     Fire
 */

/*
 * Microsoft OpenGL header can't work properly without <windows.h>.
 */
#if defined(_WIN32)
#include <windows.h>
#endif

#include <GL/gl.h>

GLvoid init_GL_state(void);
void display(void);
void reshape(GLint width, GLint height);

#endif
