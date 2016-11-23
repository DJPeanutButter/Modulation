#include "Color.h"

Color::Color (){
	r = 0.0f;
	g = 0.0f;
	b = 0.0;
}

Color::Color (float red, float green, float blue){
	r = red;
	g = green;
	b = blue;
}

Color COLOR (float r, float g, float b){
	Color retVal;
	retVal.r = r;
	retVal.g = g;
	retVal.b = b;
	return retVal;
}

Color INVERT (Color &c){
	c.r = 1.0f - c.r;
	c.g = 1.0f - c.g;
	c.b = 1.0f - c.b;
	return c;
}

void SetColor (Color c){
	glColor3f (c.r, c.g, c.b);
	return;
}
