#ifndef _ELEMENTS_H_
#define _ELEMENTS_H_

#if defined(_WIN32)
#include <windows.h>
#endif
#include <GL/gl.h>

#define OPACITY         ((100) / 100.0F)

enum {
    RED,
    GRN,
    BLU,
    CVG,

    NUMBER_OF_COMPONENTS
};

enum {
    EARTH,
    WATER,
    FIRE,
    METAL, /* wind / air, in Japanese philosophy */
    WOOD, /* void / sky, in Japanese philosophy */

    NUMBER_OF_ELEMENTS
};

static const char* elements[NUMBER_OF_ELEMENTS] = {
    "Earth",
    "Water",
    "Fire",
    "Wind", /* "metal" in the Chinese Wu Xing */
    "Void", /* "wood" in the Chinese Wu Xing */
};

static const GLfloat colors[NUMBER_OF_ELEMENTS][NUMBER_OF_COMPONENTS] = {
    { 1, 1, 0, OPACITY, }, /* "Yellow Dragon" (earth, center) */
    { 0, 0, 1, OPACITY, }, /* "Black Tortoise" (water, north) */
    { 1, 0, 0, OPACITY, }, /* "Vermillion Bird" (fire, south) */
    { 1, 1, 1, OPACITY, }, /* "White Tiger" (metal, west) */
    { 0, 1, 0, OPACITY, }, /* "Green Dragon" (wood, east) */
};

extern int counts[NUMBER_OF_ELEMENTS];

extern int primary_element(long year);
extern int fixed_element(long year);
extern int ascendant_element(unsigned long hour);
extern int lunar_element(unsigned long sign);

#endif
