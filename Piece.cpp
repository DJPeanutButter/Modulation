#include "Piece.h"

Piece::Piece (){	
	alive	= true;
	row	= 0;
	col	= 0;
	type	= 0;
	dir	= 0;
}

Piece::Piece (Color clr){
	alive	= true;
	
	row	= 0;
	col 	= 0;
	type	= 0;
	dir	= 0;
	
	color.r	= clr.r;
	color.g	= clr.g;
	color.b	= clr.b;
}

Piece::Piece (Color clr, char t){
	alive	= true;
	
	row	= 0;
	col	= 0;
	type	= t;
	dir	= 0;
	
	color.r	= clr.r;
	color.g	= clr.g;
	color.b	= clr.b;
}

Piece::Piece (Color clr, char r, char c){
	alive	= true;
	
	row	= r;
	col	= c;
	type	= 0;
	dir	= 0;
	
	color.r	= clr.r;
	color.g	= clr.g;
	color.b	= clr.b;
}

Piece::Piece (Color clr, char r, char c, char t){
	alive	= true;
	
	row	= r;
	col	= c;
	type	= t;
	dir	= 0;
	
	color.r	= clr.r;
	color.g	= clr.g;
	color.b	= clr.b;
}

Piece::Piece (char t){
	alive	= true;
	
	row	= 0;
	col	= 0;
	type	= t;
	dir	= 0;
}

Piece::Piece (char r, char c){
	alive	= true;
	
	row	= r;
	col	= c;
	type	= 0;
	dir	= 0;
}

Piece::Piece (char r, char c, char t){
	alive	= true;
	
	row	= r;
	col	= c;
	type	= t;
	dir	= 0;
}

void Piece::draw (){
	if (not alive)
		return;
	
	double dR = 2.0/(double)GD_ROWS;
	double dC = 2.0/(double)GD_COLS;
	double Cx = dC * col - 1.0 + dC/2.0;
	double Cy = 1.0 - (dR * row + dR/2.0);
	
	if (type == PT_CIRCLE){
		glColor3f (color.r, color.g, color.b);
		glPushMatrix ();
		glTranslated (Cx, Cy, 0.0);
		glBegin (GL_TRIANGLE_FAN);
		glVertex2d (0.0, 0.0);
		
		for (int i=0;i<30;i++)
			glVertex2d (cos (2.0*i*PI/30.0)*dC*0.4, sin (2.0*i*PI/30.0)*dR*0.4);
		
		glVertex2d (dC * 0.4, 0.0);
		glEnd ();
		glPopMatrix ();
	}else if (type == PT_FAN){
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix ();
		glTranslated (Cx, Cy, 0.0);
		glBegin		(GL_TRIANGLES);
		glVertex2d	(0.0, 0.0);
		
		for (int i=0;i<30;i++) {
			glVertex2d (cos (2.0*i*PI/30.0)*dC*0.4, sin (2.0*i*PI/30.0)*dR*0.4);
			if (i%2==1)
				glVertex2d (0.0, 0.0);
		}
		
		glVertex2d	(dC * 0.4, 0.0);
		glEnd		();
		glPopMatrix	();
	}else if (type == PT_SELECT){
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix	();
		glTranslated	(Cx, Cy, 0.0);
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(-3.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-dC/2.0, dR/2.0);
		glVertex2d	(-3.0*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(-dC/2.0, -dR/2.0);
		glVertex2d	(3.0*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(dC/2.0, -dR/2.0);
		glVertex2d	(3.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(dC/2.0, dR/2.0);
		glVertex2d	(-3.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-dC/2.0, dR/2.0);
		glEnd		();
		glPopMatrix	();
	}else if (type == PT_OPTION){
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix	();
		glTranslated	(Cx, Cy, 0.0);
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(-3.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-3.0*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(3.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(3.0*dC/8.0, -3.0*dR/8.0);
		glEnd		();
		glPopMatrix	();
	}else if (type == PT_ROOK){
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix	();
		glTranslated	(Cx, Cy, 0.0);
		glBegin		(GL_TRIANGLE_FAN);
		glVertex2d	(0.0, 0.0);
		glVertex2d	(3.0*dC/8.0, 1.0*dR/8.0);
		glVertex2d	(1.0*dC/8.0, 1.0*dR/8.0);
		glVertex2d	(1.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-1.0*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-1.0*dC/8.0, 1.0*dR/8.0);
		glVertex2d	(-3.0*dC/8.0, 1.0*dR/8.0);
		glVertex2d	(-3.0*dC/8.0, -1.0*dR/8.0);
		glVertex2d	(-1.0*dC/8.0, -1.0*dR/8.0);
		glVertex2d	(-1.0*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(1.0*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(1.0*dC/8.0, -1.0*dR/8.0);
		glVertex2d	(3.0*dC/8.0, -1.0*dR/8.0);
		glVertex2d	(3.0*dC/8.0, 1.0*dR/8.0);
		glEnd		();
		glPopMatrix	();
	}else if (type == PT_BISHOP){
		dR = (dC + dR)/2.0;
		dC = dR;
		
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix	();
		glTranslated	(Cx, Cy, 0.0);
		glRotated 	(45.0, 0.0, 0.0, 1.0);
		glBegin		(GL_TRIANGLE_FAN);
		glVertex2d	(0.0, 0.0);
		glVertex2d	(3.0*dC/8.0, 0.5*dR/8.0);
		glVertex2d	(0.5*dC/8.0, 0.5*dR/8.0);
		glVertex2d	(0.5*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-0.5*dC/8.0, 3.0*dR/8.0);
		glVertex2d	(-0.5*dC/8.0, 0.5*dR/8.0);
		glVertex2d	(-3.0*dC/8.0, 0.5*dR/8.0);
		glVertex2d	(-3.0*dC/8.0, -0.5*dR/8.0);
		glVertex2d	(-0.5*dC/8.0, -0.5*dR/8.0);
		glVertex2d	(-0.5*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(0.5*dC/8.0, -3.0*dR/8.0);
		glVertex2d	(0.5*dC/8.0, -0.5*dR/8.0);
		glVertex2d	(3.0*dC/8.0, -0.5*dR/8.0);
		glVertex2d	(3.0*dC/8.0, 0.5*dR/8.0);
		glEnd		();
		glPopMatrix	();
	}else if (type == PT_KNIGHT){
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix	();
		glTranslated	(Cx, Cy, 0.0);
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(3.0*dC/40.0, 3.0*dR/8.0);
		glVertex2d	(3.0*dC/40.0, 9.0*dR/40.0);
		glVertex2d	(9.0*dC/40.0, 3.0*dR/8.0);
		glVertex2d	(9.0*dC/40.0, 9.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(9.0*dC/40.0, 9.0*dR/40.0);
		glVertex2d	(9.0*dC/40.0, 3.0*dR/40.0);
		glVertex2d	(3.0*dC/8.0, 9.0*dR/40.0);
		glVertex2d	(3.0*dC/8.0, 3.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(3.0*dC/40.0, -3.0*dR/8.0);
		glVertex2d	(3.0*dC/40.0, -9.0*dR/40.0);
		glVertex2d	(9.0*dC/40.0, -3.0*dR/8.0);
		glVertex2d	(9.0*dC/40.0, -9.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(9.0*dC/40.0, -9.0*dR/40.0);
		glVertex2d	(9.0*dC/40.0, -3.0*dR/40.0);
		glVertex2d	(3.0*dC/8.0, -9.0*dR/40.0);
		glVertex2d	(3.0*dC/8.0, -3.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(-3.0*dC/40.0, 3.0*dR/8.0);
		glVertex2d	(-3.0*dC/40.0, 9.0*dR/40.0);
		glVertex2d	(-9.0*dC/40.0, 3.0*dR/8.0);
		glVertex2d	(-9.0*dC/40.0, 9.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(-9.0*dC/40.0, 9.0*dR/40.0);
		glVertex2d	(-9.0*dC/40.0, 3.0*dR/40.0);
		glVertex2d	(-3.0*dC/8.0, 9.0*dR/40.0);
		glVertex2d	(-3.0*dC/8.0, 3.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(-3.0*dC/40.0, -3.0*dR/8.0);
		glVertex2d	(-3.0*dC/40.0, -9.0*dR/40.0);
		glVertex2d	(-9.0*dC/40.0, -3.0*dR/8.0);
		glVertex2d	(-9.0*dC/40.0, -9.0*dR/40.0);
		glEnd		();
		glBegin		(GL_TRIANGLE_STRIP);
		glVertex2d	(-9.0*dC/40.0, -9.0*dR/40.0);
		glVertex2d	(-9.0*dC/40.0, -3.0*dR/40.0);
		glVertex2d	(-3.0*dC/8.0, -9.0*dR/40.0);
		glVertex2d	(-3.0*dC/8.0, -3.0*dR/40.0);
		glEnd		();
		glPopMatrix	();
	}else if (type == PT_QUEEN){
		glColor3f	(color.r, color.g, color.b);
		glPushMatrix	();
		glTranslated	(Cx, Cy, 0.0);
		glBegin		(GL_TRIANGLES);
		for (int i=0;i<16;i++) {
			glVertex2d (cos (i*PI/8.0-PI/16.0)*dC*0.325, sin (i*PI/8.0-PI/16.0)*dR*0.325);
			if (i%2==1)
				glVertex2d (0.0, 0.0);
		}
		glVertex2d	(dC * 0.325, 0.0);
		glEnd		();
		glPopMatrix	();
	}
	return;
}

