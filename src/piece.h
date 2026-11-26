#ifndef _PIECE_H_
#define _PIECE_H_

#include "constants.h"

#include <vector>

class board_t;
class move_t;

class piece_t {
public:
	color_t color;
	type_t type;

	piece_t(color_t, type_t);
	virtual std::vector<move_t> get_moves(board_t, size_t, size_t) = 0;
};

class pawn_t : piece_t {
public:
	pawn_t(color_t);
	std::vector<move_t> get_moves(board_t, size_t, size_t);
};

class knight_t : piece_t {
public:
	knight_t(color_t);
	std::vector<move_t> get_moves(board_t, size_t, size_t);
};

class bishop_t : piece_t {
public:
	bishop_t(color_t);
	std::vector<move_t> get_moves(board_t, size_t, size_t);
};

class rook_t : piece_t {
public:
	rook_t(color_t);
	std::vector<move_t> get_moves(board_t, size_t, size_t);
};

class queen_t : piece_t {
public:
	queen_t(color_t);
	std::vector<move_t> get_moves(board_t, size_t, size_t);
};

class king_t : piece_t {
public:
	king_t(color_t);
	std::vector<move_t> get_moves(board_t, size_t, size_t);
};

#endif
