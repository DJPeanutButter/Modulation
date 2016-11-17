#include "Color.h"

Struct Piece{
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
