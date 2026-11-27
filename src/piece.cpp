#include "piece.h"
#include "board.h"

namespace {
	void add_pawn_move(std::vector <move_t>&moves, int from, int to, int last_rank) {
		if ( rank_of(to) == last_rank ) {
			moves.emplace_back(from, to, type_t::QUEEN);
			moves.emplace_back(from, to, type_t::ROOK);
			moves.emplace_back(from, to, type_t::BISHOP);
			moves.emplace_back(from, to, type_t::KNIGHT);
		} else {
			moves.emplace_back(from, to);
		}
	}
}

piece_t::piece_t(color_t color, type_t type)
	: color { color }, type { type } {}

pawn_t::pawn_t(color_t color)
	: piece_t { color, type_t::PAWN } {}

knight_t::knight_t(color_t color)
	: piece_t { color, type_t::KNIGHT } {}

bishop_t::bishop_t(color_t color)
	: piece_t { color, type_t::BISHOP } {}

rook_t::rook_t(color_t color)
	: piece_t { color, type_t::ROOK } {}

queen_t::queen_t(color_t color)
	: piece_t { color, type_t::QUEEN } {}

king_t::king_t(color_t color)
	: piece_t { color, type_t::KING } {}

std::vector<move_t> pawn_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	const int dir = (color == color_t::WHITE) ? 1 : -1;
	const int start_rank = (color == color_t::WHITE) ? 1 : 6;
	const int last_rank = (color == color_t::WHITE) ? 7 : 0;
	const int file = file_of(sq);
	const int rank = rank_of(sq);
	const int next_rank = rank + dir;
	if ( next_rank > 7 || next_rank < 0 ) {
		return {};
	}
	const int one = square_index(file, next_rank);
	if (board.squares[one] == nullptr) {
		add_pawn_move(v, sq, one, last_rank);
		if (rank == start_rank) {
			const int two = square_index(file, rank + 2 * dir);
			if (board.squares[two] == nullptr) {
				add_pawn_move(v, sq, two, last_rank);
			} 
		}
	}
	const int df[2] = {-1, 1};
	for ( const int elem : df ) {
		const int f = file + elem;
		if ( f < 0 or f > 7 ) {
			continue;
		}
		const int target = square_index(f, next_rank);
		const piece_t* p = board.squares[target];
		if ( p != nullptr && p->color != color ) {
			add_pawn_move(v, sq, target, last_rank);
		}
	}
	/// en-pansant is an TODO - not finished
	return v;
}

std::vector<move_t> knight_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

std::vector<move_t> bishop_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

std::vector<move_t> rook_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

std::vector<move_t> queen_t::get_moves(const board_t& board, int sq) const{
	std::vector<move_t> v;
	return v;
}

std::vector<move_t> king_t::get_moves(const board_t& board, int sq) const {
	std::vector<move_t> v;
	return v;
}
