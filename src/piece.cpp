#include "piece.h"

piece_t::piece_t(color_t color, type_t type)
	: color { color }, type { type } {}

pawn_t::pawn_t(color_t color)
	: piece_t { color, PAWN } {}

std::vector<move_t> pawn_t::get_moves(board_t board, size_t rank, size_t file) {
	vector<move_t> v;
	return v;
}

knight_t::knight_t(color_t color)
	: piece_t { color, KNIGHT } {}

std::vector<move_t> knight_t::get_moves(board_t board, size_t rank, size_t file) {
	vector<move_t> v;
	return v;
}

bishop_t::bishop_t(color_t color)
	: piece_t { color, BISHOP } {}

std::vector<move_t> bishop_t::get_moves(board_t board, size_t rank, size_t file) {
	vector<move_t> v;
	return v;
}

rook_t::rook_t(color_t color)
	: piece_t { color, ROOK } {}

std::vector<pair<int,int>> rook_t::get_moves(board_t board, size_t rank, size_t file) {
	vector<move_t> v;
	return v;
}

queen_t::queen_t(color_t color)
	: piece_t { color, QUEEN } {}

std::vector<pair<int,int>> queen_t::get_moves(board_t board, size_t rank, size_t file) {
	vector<move_t> v;
	return v;
}

king_t::king_t(color_t color)
	: piece_t { color, KING } {}

std::vector<pair<int,int>> king_t::get_moves(board_t board, size_t rank, size_t file) {
	vector<move_t> v;
	return v;
}
