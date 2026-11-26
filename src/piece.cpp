#include "piece.h"

piece_t::piece_t(color_t color, type_t type)
	: color { color }, type { type } {}

pawn_t::pawn_t(color_t color)
	: piece_t { color, type_t::PAWN } {}

std::vector<move_t> pawn_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

knight_t::knight_t(color_t color)
	: piece_t { color, type_t::KNIGHT } {}

std::vector<move_t> knight_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

bishop_t::bishop_t(color_t color)
	: piece_t { color, type_t::BISHOP } {}

std::vector<move_t> bishop_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

rook_t::rook_t(color_t color)
	: piece_t { color, type_t::ROOK } {}

std::vector<move_t> rook_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

queen_t::queen_t(color_t color)
	: piece_t { color, type_t::QUEEN } {}

std::vector<move_t> queen_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

king_t::king_t(color_t color)
	: piece_t { color, type_t::KING } {}

std::vector<move_t> king_t::get_moves(const board_t& board, int sq) const {
	std::vector<move_t> v;
	return v;
}
