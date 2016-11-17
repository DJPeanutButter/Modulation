#ifndef _COLOR_H_
#define _COLOR_H_

#include <iostream>
#include <vector>
#include <windows.h>
#include <gl/gl.h>
#include <math.h>

#define GD_COLS 16
#define GD_ROWS 24

struct Color{
	float r, g, b;
	
	Color ();
	Color (float r, float g, float b);
};

Color		COLOR		(float r, float g, float b);
Color		INVERT		(Color &c);
void inline	SetColor	(Color c);

#endif
