#ifndef _PIECE_H_
#define _PIECE_H_

#include "constants.h"

class piece_t {
	color_t color;
	type_t type;

	piece_t(color_t, type_t);
};

class pawn_t : piece_t {
};

class knight_t : piece_t {
};

class bishop_t : piece_t {
}

class rook_t : piece_t {
};

class queen_t : piece_t {
};

class king_t : piece_t {
};

#endif
