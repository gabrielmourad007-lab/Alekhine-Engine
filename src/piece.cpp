#include "piece.h"

piece_t::piece_t(color_t color, type_t type)
	: color { color }, type { type } {}

pawn_t::pawn_t(color_t color)
	: piece_t { color, PAWN } {}

knight_t::knight_t(color_t color)
	: piece_t { color, KNIGHT } {}

bishop_t::bishop_t(color_t color)
	: piece_t { color, BISHOP } {}

rook_t::rook_t(color_t color)
	: piece_t { color, ROOK } {}

queen_t::queen_t(color_t color)
	: piece_t { color, QUEEN } {}

king_t::king_t(color_t color)
	: piece_t { color, KING } {}
