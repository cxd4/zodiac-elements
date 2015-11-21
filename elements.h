#ifndef _ELEMENTS_H_
#define _ELEMENTS_H_

enum {
    YANG,
    YIN,

    YIN_YANG
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

/*
 * the conducive cycle of the five elements:
 *     1.  Metal supports/produces Water.
 *     2.  Water supports/produces Wood.
 *     3.  Wood supports/produces Fire.
 *     4.  Fire supports/produces Earth.
 *     5.  Earth supports/produces Metal.
 */
enum {
    WATER_VERTEX,
    METAL_VERTEX,
    EARTH_VERTEX,
    FIRE_VERTEX,
    WOOD_VERTEX,

    NUMBER_OF_VERTICES
};

extern int counts[NUMBER_OF_ELEMENTS];
extern int final_element;

extern int primary_element(long year);
extern int fixed_element(long year);
extern int ascendant_element(unsigned long hour);
extern int lunar_element(unsigned long sign);

#endif
