#ifndef _PIECE_H_
#define _PIECE_H_

#include "constants.h"

#include <vector>

class board_t;

class piece_t {
public:
	color_t color;
	type_t type;

	piece_t(color_t, type_t);

	virtual std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>) = 0;
};

class pawn_t : piece_t {
public:
	pawn_t(color_t);

	std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>);
};

class knight_t : piece_t {
public:
	knight_t(color_t);

	std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>);
};

class bishop_t : piece_t {
public:
	bishop_t(color_t);

	std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>);
};

class rook_t : piece_t {
public:
	rook_t(color_t);

	std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>);
};

class queen_t : piece_t {
public:
	queen_t(color_t);

	std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>);
};

class king_t : piece_t {
public:
	king_t(color_t);

	std::vector<std::pair<int, int>> get_moves(board_t, std::pair<int, int>);
};

#endif
