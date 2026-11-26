#ifndef _PIECE_H_
#define _PIECE_H_

#include "constants.h"
#include "move.h"

#include <vector>

class board_t;

class piece_t {
public:
	color_t color;
	type_t type;

	piece_t(color_t, type_t);
	virtual ~piece_t() = default;
	virtual std::vector<move_t> get_moves(const board_t&, int) const  = 0;
};

class pawn_t : public piece_t {
public:
	pawn_t(color_t);
	std::vector<move_t> get_moves(const board_t&, int) const override;
};

class knight_t : public piece_t {
public:
	knight_t(color_t);
	std::vector<move_t> get_moves(const board_t&, int)const override;
};

class bishop_t : public piece_t {
public:
	bishop_t(color_t);
	std::vector<move_t> get_moves(const board_t&, int) const override;
};

class rook_t : public piece_t {
public:
	rook_t(color_t);
	std::vector<move_t> get_moves(const board_t&, int) const override;
};

class queen_t : public piece_t {
public:
	queen_t(color_t);
	std::vector<move_t> get_moves(const board_t&, int) const override;
};

class king_t : public piece_t {
public:
	king_t(color_t);
	std::vector<move_t> get_moves(const board_t&, int) const override;
};

#endif
