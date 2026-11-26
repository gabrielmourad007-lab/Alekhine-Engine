#include "piece.h"

piece_t::piece_t(color_t color, type_t type)
	: color { color }, type { type } {}

pawn_t::pawn_t(color_t color)
	: piece_t { color, PAWN } {}

std::vector<pair<int,int>> pawn_t::get_moves(pair<int,int> position) {
	vector<pair<int,int>> v;
	v.push_back(position);
	return v;
}

knight_t::knight_t(color_t color)
	: piece_t { color, KNIGHT } {}

std::vector<pair<int,int>> knight_t::get_moves(pair<int,int> position) {
	vector<pair<int,int>> v;
	v.push_back(position);
	return v;
}

bishop_t::bishop_t(color_t color)
	: piece_t { color, BISHOP } {}

std::vector<pair<int,int>> bishop_t::get_moves(pair<int,int> position) {
	vector<pair<int,int>> v;
	v.push_back(position);
	return v;
}

rook_t::rook_t(color_t color)
	: piece_t { color, ROOK } {}

std::vector<pair<int,int>> rook_t::get_moves(pair<int,int> position) {
	vector<pair<int,int>> v;
	v.push_back(position);
	return v;
}

queen_t::queen_t(color_t color)
	: piece_t { color, QUEEN } {}

std::vector<pair<int,int>> queen_t::get_moves(pair<int,int> position) {
	vector<pair<int,int>> v;
	v.push_back(position);
	return v;
}

king_t::king_t(color_t color)
	: piece_t { color, KING } {}

std::vector<pair<int,int>> king_t::get_moves(pair<int,int> position) {
	vector<pair<int,int>> v;
	v.push_back(position);
	return v;
}
