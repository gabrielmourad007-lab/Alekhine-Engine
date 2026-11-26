#include "board.h"

board_t::board_t()
  : squares(square_count, piece_t(color_t::WHITE, type_t::EMPTY)),
    side_to_move(color_t::WHITE) {
  set_starting_position();
}

void board_t::set_starting_position() {
  squares.assign(square_count, piece_t(color_t::WHITE, type_t::EMPTY));

  const type_t back_rank[8]
    = {type_t::ROOK, type_t::KNIGHT, type_t::BISHOP, type_t::QUEEN,
       type_t::KING, type_t::BISHOP, type_t::KNIGHT, type_t::ROOK};

  for(int file = 0; file < 8; ++file) {
    squares[square_index(file, 0)] = piece_t(color_t::WHITE, back_rank[file]);
    squares[square_index(file, 1)] = piece_t(color_t::WHITE, type_t::PAWN);
    squares[square_index(file, 6)] = piece_t(color_t::BLACK, type_t::PAWN);
    squares[square_index(file, 7)] = piece_t(color_t::BLACK, back_rank[file]);
  }

  side_to_move = color_t::WHITE;
}
  side_to_move = color_t::WHITE;
}

bool board_t::apply_move(int from, int to) {
  if(!is_valid_square(from) || !is_valid_square(to))
    return false;

  const piece_t moving = squares[from];
  if(moving.type == type_t::EMPTY || moving.color != side_to_move)
    return false;

  squares[to] = moving;
  squares[from] = piece_t(color_t::WHITE, type_t::EMPTY);

  side_to_move
    = side_to_move == color_t::WHITE ? color_t::BLACK : color_t::WHITE;
  return true;
}