#ifndef _PIECE_H_
#define _PIECE_H_

#include "constants.h"

class piece_t {
	color_t color;
	type_t type;

public:
	piece_t(color_t, type_t);
};

class pawn_t : piece_t {
public:
	pawn_t(color_t);
};

class knight_t : piece_t {
public:
	knight_t(color_t);
};

class bishop_t : piece_t {
public:
	bishop_t(color_t);
}

class rook_t : piece_t {
public:
	rook_t(color_t);
};

class queen_t : piece_t {
public:
	queen_t(color_t);
};

class king_t : piece_t {
public:
	king_t(color_t);
};

#endif
