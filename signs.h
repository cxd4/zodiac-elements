#ifndef _SIGNS_H_
#define _SIGNS_H_

/*
 * Western zodiac
 * solar signs
 */
enum {
    ARIES, /* cardinal, spring */
    TAURUS,
    GEMINI,

    CANCER, /* cardinal, summer */
    LEO,
    VIRGO,

    LIBRA, /* cardinal, autumn */
    SCORPIO,
    SAGITTARIUS,

    CAPRICORN, /* cardinal, winter */
    AQUARIUS,
    PISCES,

    NUMBER_OF_SIGNS
};

/*
 * Eastern zodiac
 * lunar signs
 */
enum {
 /* BOAR, */
    RAT,
    OX, /* Water representative */

    TIGER,
    RABBIT,
    DRAGON, /* Wood representative */

    SNAKE,
    HORSE,
    SHEEP, /* Fire representative */

/*
 * In terms of seasons, Earth comes between Fire (summer) and Metal (autumn).
 * However, the Earth element can't be appointed to any of the twelve signs.
 *
 * Some astrologers prefer to appoint Earth as the secondary element to each
 * of the four representative signs:  Ox, Dragon, Sheep, and Dog
 */

    MONKEY,
    ROOSTER,
    DOG, /* Metal representative */

    BOAR,

    NUMBER_OF_ANIMAL_SIGNS
};

static const char* signs[NUMBER_OF_SIGNS] = {
    "Aries"      ,"Taurus"     ,"Gemini"     ,"Cancer"     ,
    "Leo"        ,"Virgo"      ,"Libra"      ,"Scorpio"    ,
    "Sagittarius","Capricorn"  ,"Aquarius"   ,"Pisces"     ,
};

static const char* animals[NUMBER_OF_ANIMAL_SIGNS] = {
    "Rat"    ,"Ox"     ,"Tiger"  ,"Rabbit" ,
    "Dragon" ,"Snake"  ,"Horse"  ,"Sheep"  ,
    "Monkey" ,"Rooster","Dog"    ,"Boar"   ,
};

#endif
