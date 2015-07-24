#include <math.h>

#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>
#include <GL/gl.h>

#include "elements.h"
#include "input.h"

int counts[NUMBER_OF_ELEMENTS];

int main(int argc, char ** argv)
{
    long input;
    int output;

    if (argc < 2)
        fputs("Enter year (negative for B.C.):  ", stdout);
    input = (argc < 2)
      ? scan_long()
      : strtol(argv[1], NULL, 0)
    ;
    output = primary_element(input);
    ++counts[output];

    printf("Annual element   :  %s\n", elements[output]);
    printf("Fixed element    :  %s\n", "to do...");
    printf("Ascendant element:  %s\n", "to do...");
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
