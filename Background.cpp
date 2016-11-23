#include "Background.h"

void DrawBackground (Color c1, Color c2){
	float dR = 2.0f/(float)GD_ROWS;
	float dC = 2.0f/(float)GD_COLS;
	
	glBegin		(GL_TRIANGLES);
	SetColor	(c1);
	
	glVertex2f	(-1.0f, -1.0f);
	glVertex2f	( 1.0f, -1.0f);
	glVertex2f	(-1.0f,	 1.0f);
	
	glVertex2f	( 1.0f, -1.0f);
	glVertex2f	(-1.0f,	 1.0f);
	glVertex2f	( 1.0f,  1.0f);
	
	SetColor	(c2);
	
	for (char i=0;i<GD_COLS;i++){
		for (char j=0;j<GD_ROWS;j++){
			if ((i+j)%2==1)
				continue;
			glVertex2f (-1.0f+(float)i*dC,		-1.0f+(float)j*dR);
			glVertex2f (-1.0f+(float)i*dC+dC,	-1.0f+(float)j*dR);
			glVertex2f (-1.0f+(float)i*dC,		-1.0f+(float)j*dR+dR);
			
			glVertex2f (-1.0f+(float)i*dC+dC,	-1.0f+(float)j*dR);
			glVertex2f (-1.0f+(float)i*dC,		-1.0f+(float)j*dR+dR);
			glVertex2f (-1.0f+(float)i*dC+dC,	-1.0f+(float)j*dR+dR);
		}
	}
	glEnd ();
	return;
}
