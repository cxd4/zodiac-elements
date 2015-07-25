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

#include <math.h>
#ifndef M_PI
#define M_PI    3.1415926535897932384626433832795
#endif

#define cosd(degrees)           cos(M_PI * (degrees) / 180.)
#define sind(degrees)           sin(M_PI * (degrees) / 180.)
#define sqr(x)                  ((x) * (x))
#define cosd2(degrees)          sqr(cosd2(degrees))
#define sind2(degrees)          sqr(sind2(degrees))

#include "elements.h"
#define RADIUS                  1.0
#define POLYGON_DEPTH           NUMBER_OF_ELEMENTS

#define RIGHT_ANGLE_DEGREES     90

#define DEGREES_PER_CIRCLE      360
#define DEGREES_PER_TRIANGLE    (90 + 60 + 30)
#define DEGREES_PER_POLYGON     ((DEGREES_PER_TRIANGLE) * ((POLYGON_DEPTH) - 2))
#define DEGREES_PER_ANGLE       ((DEGREES_PER_POLYGON) / (POLYGON_DEPTH))

/*
 * counter-clockwise rotation of the pentagon, in degrees (like a protractor)
 * This is so the perfect pentagon faces upwards instead of to the right.
 *
 * Triangle Sum Theorem:  angle_A + angle_B + angle_C = 180 [degrees]
 * So the rotation angle should be 180 - x - (right_angle = 90).
 */
#define COMPLIMENT(degrees)     ((RIGHT_ANGLE_DEGREES) - (degrees))
#define SUPPLEMENT(degrees)     ((DEGREES_PER_TRIANGLE) - (degrees))
#define INTERVAL                SUPPLEMENT(DEGREES_PER_ANGLE)
#define ROTATION                COMPLIMENT(INTERVAL)

#define BACK_PLANE              -1
#define DONT_CARE               0
#define FRONT_PLANE             +1
#define PLANE_Z                 DONT_CARE

#define OPACITY         ((100) / 100.0F)

enum {
    X, /* axial position, wrt. right and left */
    Y, /* axial position, wrt. up and down */
    Z, /* axial position, wrt. front and back */
    W, /* inverse depth coefficient:  (x/w, y/w, z/w); 3-D radius = (1 / w) */

    NUMBER_OF_COORDINATES
};
enum {
    RED,
    GRN,
    BLU,
    CVG,

    NUMBER_OF_COMPONENTS
};

GLvoid init_GL_state(void);
void display(void);
void reshape(GLsizei width, GLsizei height);

#endif
