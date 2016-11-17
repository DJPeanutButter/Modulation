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

Piece* SelectPiece (char r, char c, Piece* arrPieces, int lPieces){
	for (int i=0;i<lPieces;i++)
		if (arrPieces[i].row == r and arrPieces[i].col == c)
			return &arrPieces[i];
	return NULL;
}

Piece* SelectPiece (char r, char c, std::vector<Piece> &p){
	for (int i=0;i<p.size();i++)
		if (p[i].row == r and p[i].col == c)
			return &p[i];
	return NULL;
}

void MovePiece (Piece &p, char r, char c){
	p.row = r;
	p.col = c;
	return;
}

std::vector<Piece> FindMoves (Piece &p){
	std::vector<Piece>	retVal;
	Piece			temp;
	
	temp.color	= COLOR (1.0f, 1.0f, 1.0f);
	temp.type	= PT_OPTION;
	
	int o = 0;
	switch (p.type){
		case PT_QUEEN:
		case PT_ROOK:
			/*119*/
			temp.row = p.row;
			for (int i=0;i<GD_COLS;i++){
				if (p.col == i){
					continue;
				}
				temp.col = i;
				retVal.push_back (temp);
			}
			temp.col = p.col;
			for (int i=0;i<GD_ROWS;i++){
				if (p.row == i){
					continue;
				}
				temp.row = i;
				retVal.push_back (temp);
			}//*/
			/*105-135
			for (int d=1;p.row-d>=0 or p.row+d<GD_ROWS or p.col-d>=0 or p.col+d<GD_COLS;d++){
				if (p.row-d>=0){
					temp.row = p.row-d;
					temp.col = p.col;
					retVal.push_back (temp);
				}
				if (p.row+d<GD_ROWS){
					temp.row = p.row+d;
					temp.col = p.col;
					retVal.push_back (temp);
				}
				if (p.col-d>=0){
					temp.row = p.row;
					temp.col = p.col-d;
					retVal.push_back (temp);
				}
				if (p.col+d<GD_COLS){
					temp.row = p.row;
					temp.col = p.col+d;
					retVal.push_back (temp);
				}
			}
			//*/
			if (p.type != PT_QUEEN)
				break;
		case PT_BISHOP:
			for (int d=1;p.row-d>=0;d++){
				if (p.col-d>=0){
					temp.row = p.row-d;
					temp.col = p.col-d;
					retVal.push_back (temp);
				}
				if (p.col+d<GD_COLS){
					temp.row = p.row-d;
					temp.col = p.col+d;
					retVal.push_back (temp);
				}
			}
			for (int d=1;p.row+d<GD_ROWS;d++){
				if (p.col-d>=0){
					temp.row = p.row+d;
					temp.col = p.col-d;
					retVal.push_back (temp);
				}
				if (p.col+d<GD_COLS){
					temp.row = p.row+d;
					temp.col = p.col+d;
					retVal.push_back (temp);
				}
			}
			break;
		case PT_KING:
			temp.row = p.row+1;
			temp.col = p.col+1;
			retVal.push_back (temp);
			temp.col = p.col;
			retVal.push_back (temp);
			temp.col = p.col-1;
			retVal.push_back (temp);
			temp.row = p.row;
			retVal.push_back (temp);
			temp.col = p.col+1;
			retVal.push_back (temp);
			temp.row = p.row-1;
			retVal.push_back (temp);
			temp.col = p.col;
			retVal.push_back (temp);
			temp.col = p.col-1;
			retVal.push_back (temp);
			break;
		case PT_KNIGHT:
			temp.row = p.row+2;
			temp.col = p.col+1;
			retVal.push_back (temp);
			temp.col = p.col-1;
			retVal.push_back (temp);
			temp.row = p.row+1;
			temp.col = p.col+2;
			retVal.push_back (temp);
			temp.col = p.col-2;
			retVal.push_back (temp);
			temp.row = p.row-1;
			retVal.push_back (temp);
			temp.col = p.col+2;
			retVal.push_back (temp);
			temp.row = p.row-2;
			temp.col = p.col+1;
			retVal.push_back (temp);
			temp.col = p.col-1;
			retVal.push_back (temp);
			break;
		default:
			break;
	}
	return retVal;
}

std::vector<Piece> FindMoves (Piece &p, std::vector<Piece> pieces){
	std::vector<Piece>	retVal;
	Piece			temp;
	
	temp.color	= COLOR (1.0f, 1.0f, 1.0f);
	temp.type	= PT_OPTION;
	switch (p.type){
		case PT_QUEEN:
		case PT_ROOK:
			/*119
			temp.row = p.row;
			for (int i=0;i<GD_COLS;i++){
				if (p.col == i){
					continue;
				}
				temp.col = i;
				retVal.push_back (temp);
			}
			temp.col = p.col;
			for (int i=0;i<GD_ROWS;i++){
				if (p.row == i){
					continue;
				}
				temp.row = i;
				retVal.push_back (temp);
			}//*/
			/*105-135*/
			temp.col = p.col;
			for (temp.row=p.row-1;temp.row>=0;temp.row--)
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			for (temp.row=p.row+1;temp.row<GD_ROWS;temp.row++)
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			temp.row = p.row;
			for (temp.col=p.col-1;temp.col>=0;temp.col--)
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			for (temp.col=p.col+1;temp.col<GD_COLS;temp.col++)
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			//*/
			if (p.type != PT_QUEEN)
				break;
		case PT_BISHOP:
			for (int d=1;p.row-d>=0;d++){
				temp.row = p.row-d;
				temp.col = p.col-d;
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			}
			for (int d=1;p.row-d>=0;d++){
				temp.row = p.row-d;
				temp.col = p.col+d;
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			}
			for (int d=1;p.row+d<GD_ROWS;d++){
				temp.row = p.row+d;
				temp.col = p.col-d;
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			}
			for (int d=1;p.row+d<GD_ROWS;d++){
				temp.row = p.row+d;
				temp.col = p.col+d;
				if (SelectPiece (temp.row, temp.col, pieces) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else
					retVal.push_back (temp);
			}
			break;
		case PT_KING:
			temp.row = p.row+1;
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.row = p.row;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.row = p.row-1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			break;
		case PT_KNIGHT:
			temp.row = p.row+2;
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.row = p.row+1;
			temp.col = p.col+2;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col-2;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.row = p.row-1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col+2;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.row = p.row-2;
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, pieces) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else
				retVal.push_back (temp);
			break;
		default:
			break;
	}
	return retVal;
}

std::vector<Piece> FindMoves (Piece &p, std::vector<Piece> friendly, std::vector<Piece> hostile){
	std::vector<Piece>	retVal;
	Piece			temp;
	
	temp.color	= COLOR (1.0f, 1.0f, 1.0f);
	temp.type	= PT_OPTION;
	switch (p.type){
		case PT_QUEEN:
		case PT_ROOK:
			/*119
			temp.row = p.row;
			for (int i=0;i<GD_COLS;i++){
				if (p.col == i){
					continue;
				}
				temp.col = i;
				retVal.push_back (temp);
			}
			temp.col = p.col;
			for (int i=0;i<GD_ROWS;i++){
				if (p.row == i){
					continue;
				}
				temp.row = i;
				retVal.push_back (temp);
			}//*/
			/*105-135*/
			temp.col = p.col;
			for (temp.row=p.row-1;temp.row>=0;temp.row--)
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			for (temp.row=p.row+1;temp.row<GD_ROWS;temp.row++)
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			temp.row = p.row;
			for (temp.col=p.col-1;temp.col>=0;temp.col--)
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			for (temp.col=p.col+1;temp.col<GD_COLS;temp.col++)
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			//*/
			if (p.type != PT_QUEEN)
				break;
		case PT_BISHOP:
			for (int d=1;p.row-d>=0;d++){
				temp.row = p.row-d;
				temp.col = p.col-d;
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			}
			for (int d=1;p.row-d>=0;d++){
				temp.row = p.row-d;
				temp.col = p.col+d;
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			}
			for (int d=1;p.row+d<GD_ROWS;d++){
				temp.row = p.row+d;
				temp.col = p.col-d;
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			}
			for (int d=1;p.row+d<GD_ROWS;d++){
				temp.row = p.row+d;
				temp.col = p.col+d;
				if (SelectPiece (temp.row, temp.col, hostile) != NULL){
					temp.color = COLOR (1.0f, 0.0f, 0.0f);
					retVal.push_back (temp);
					temp.color = COLOR (1.0f, 1.0f, 1.0f);
					break;
				}else if (SelectPiece (temp.row, temp.col, friendly) != NULL)
					break;
				else
					retVal.push_back (temp);
			}
			break;
		case PT_KING:
			temp.row = p.row+1;
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.row = p.row;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.row = p.row-1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			break;
		case PT_KNIGHT:
			temp.row = p.row+2;
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.row = p.row+1;
			temp.col = p.col+2;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col-2;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.row = p.row-1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col+2;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.row = p.row-2;
			temp.col = p.col+1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			temp.col = p.col-1;
			if (SelectPiece (temp.row, temp.col, hostile) != NULL){
				temp.color = COLOR (1.0f, 0.0f, 0.0f);
				retVal.push_back (temp);
				temp.color = COLOR (1.0f, 1.0f, 1.0f);
			}else if (SelectPiece (temp.row, temp.col, friendly) == NULL)
				retVal.push_back (temp);
			break;
		default:
			break;
	}
	return retVal;
}

int FindTarget (Piece &p, std::vector<Piece> v){
	for (int i=0;i<v.size();i++){
		if (p.row == v[i].row and p.col == v[i].col)
			return i;
	}
	return -1;
}
