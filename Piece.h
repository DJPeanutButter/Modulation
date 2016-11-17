#ifndef _PIECE_H_
#define _PIECE_H_

#include "Color.h"

#define PT_CIRCLE	0
#define PT_FAN		1
#define	PT_SELECT	2
#define PT_OPTION	3
#define PT_KNIGHT	4
#define PT_KING		5
#define PT_BISHOP	6
#define PT_ROOK		7
#define PT_QUEEN	8


#define PI	3.1415926

struct Piece{
	bool	alive;
	char	row, col, type, dir;
	Color	color;
	void	draw ();
	
	Piece ();
	Piece (Color clr);
	Piece (Color clr, char t);
	Piece (Color clr, char r, char c);
	Piece (Color clr, char r, char c, char t);
	Piece (char t);
	Piece (char r, char c);
	Piece (char r, char c, char t);
};

#endif
