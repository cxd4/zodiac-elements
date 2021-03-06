#ifndef _INPUT_H_
#define _INPUT_H_

#include <GL/glut.h>

extern void key_press(int key, int x, int y);

extern char * scan_keys(void);
extern double carry_in(void);
extern long scan_long(void);
extern unsigned long scan_unsigned(void);

#endif
