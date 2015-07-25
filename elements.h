#ifndef _ELEMENTS_H_
#define _ELEMENTS_H_

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

extern int counts[NUMBER_OF_ELEMENTS];

extern int primary_element(long year);
extern int fixed_element(long year);
extern int ascendant_element(unsigned long hour);
extern int lunar_element(unsigned long sign);

#endif
