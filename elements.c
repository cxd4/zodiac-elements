#include <math.h>

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>

#include "elements.h"
#include "input.h"
#include "signs.h"

int counts[NUMBER_OF_ELEMENTS];

int main(int argc, char ** argv)
{
    unsigned long sign, hour;
    long year;
    int element;

    if (argc < 2)
        fputs("Enter year (negative for B.C.):  ", stdout);
    year = (argc < 2)
      ? scan_long()
      : strtol(argv[1], NULL, 0)
    ;

    if (argc < 3)
        fputs("Enter sign (1 to 12; Aries=1, Pisces=12):  ", stdout);
    sign = (argc < 3)
      ? scan_unsigned()
      : strtoul(argv[2], NULL, 0)
    ;

    if (argc < 4)
        fputs("Enter hour (0 to 23):  ", stdout);
    hour = (argc < 4)
      ? scan_unsigned()
      : strtoul(argv[3], NULL, 0)
    ;

    element = primary_element(year);
    ++counts[element];
    printf("Annual element   :  %s\n", elements[element]);

    element = fixed_element(year);
    ++counts[element];
    printf("Fixed element    :  %s\n", elements[element]);

    element = ascendant_element(hour);
    ++counts[element];
    printf("Ascendant element:  %s\n", elements[element]);

    printf("Lunar element    :  %s\n", "to do...");
    return 0;
}

int primary_element(long year)
{
    switch ((10 + year%10) % 10) { /* Year ends with.... */
    case 0:
    case 1:
        return METAL;
    case 2:
    case 3:
        return WATER;
    case 4:
    case 5:
        return WOOD;
    case 6:
    case 7:
        return FIRE;
    case 8:
    case 9:

/*
 * Earth is the "default" element because it represents the composure of all
 * the other four elements, balanced together.
 *
 * If you don't know the year of birth or whatever, just pick Earth to
 * nullify/neutralize the strength of the "unknown" factor, as it is not
 * possible to have Earth as the element for the other measurements anyway.
 */
    default:
        return EARTH;
    }
}

int fixed_element(long year)
{
    int index;

    index = (int)(year % 12);
    index = (12 + index) % 12; /* in case of negative or "B.C." years */

    index += 8; /* offsets Monkey, Rooster, Dog... to Rat, Ox, Tiger... */
    switch (index %= 12) {
    case BOAR:
    case RAT:
    case OX:
        return WATER;
    case TIGER:
    case RABBIT:
    case DRAGON:
        return WOOD;
    case SNAKE:
    case HORSE:
    case SHEEP:
        return FIRE;
     /* return EARTH; */
    case MONKEY:
    case ROOSTER:
    case DOG:
        return METAL;

    default:
        return EARTH; /* unreachable -- used for balance or unknowns */
    }
}

int ascendant_element(unsigned long hour)
{
    const int offset = -8; /* Year 0 is Monkey (#8), not Rat (#1). */

    switch (hour %= 24) {
    case 23:
    case  0: /* North (Water):  11:00 PM to 1:00 AM (Rat) */
        return fixed_element(RAT + offset);
    case  1:
    case  2: /* North (Water):  1:00 AM to 3:00 AM (Ox) */
        return fixed_element(OX + offset);
    case  3:
    case  4: /* East (Wood):  3:00 AM to 5:00 AM (Tiger) */
        return fixed_element(TIGER + offset);
    case  5:
    case  6: /* East (Wood):  5:00 AM to 7:00 AM (Rabbit) */
        return fixed_element(RABBIT + offset);
    case  7:
    case  8: /* East (Wood):  7:00 AM to 9:00 AM (Dragon) */
        return fixed_element(DRAGON + offset);
    case  9:
    case 10: /* South (Fire):  9:00 AM to 11:00 AM (Snake) */
        return fixed_element(SNAKE + offset);
    case 11:
    case 12: /* South (Fire):  11:00 AM to 1:00 PM (Horse) */
        return fixed_element(HORSE + offset);
    case 13:
    case 14: /* South (Fire):  1:00 PM to 3:00 PM (Sheep) */
        return fixed_element(SHEEP + offset);
    case 15:
    case 16: /* West (Metal):  3:00 PM to 5:00 PM (Monkey) */
        return fixed_element(MONKEY + offset);
    case 17:
    case 18: /* West (Metal):  5:00 PM to 7:00 PM (Rooster) */
        return fixed_element(ROOSTER + offset);
    case 19:
    case 20: /* West (Metal):  7:00 PM to 9:00 PM (Dog) */
        return fixed_element(DOG + offset);
    case 21:
    case 22: /* North (Water):  9:00 PM to 11:00 PM (Pig) */
        return fixed_element(BOAR + offset);

    default:
        return EARTH; /* unreachable -- used for balance or unknowns */
    }
}
