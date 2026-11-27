#include "board.h"

#include <cctype>
#include <string_view>

namespace {

  const piece_t* get_piece(color_t color, type_t type) {
    static const pawn_t wp {color_t::WHITE}, bp {color_t::BLACK};
    static const knight_t wn {color_t::WHITE}, bn {color_t::BLACK};
    static const bishop_t wb {color_t::WHITE}, bb {color_t::BLACK};
    static const rook_t wr {color_t::WHITE}, br {color_t::BLACK};
    static const queen_t wq {color_t::WHITE}, bq {color_t::BLACK};
    static const king_t wk {color_t::WHITE}, bk {color_t::BLACK};

    const bool white = (color == color_t::WHITE);
    switch(type) {
      case type_t::PAWN: {
        return white ? (const piece_t*)&wp : &bp;
      }
      case type_t::KNIGHT: {
        return white ? (const piece_t*)&wn : &bn;
      }
      case type_t::BISHOP: {
        return white ? (const piece_t*)&wb : &bb;
      }
      case type_t::ROOK: {
        return white ? (const piece_t*)&wr : &br;
      }
      case type_t::QUEEN: {
        return white ? (const piece_t*)&wq : &bq;
      }
      case type_t::KING: {
        return white ? (const piece_t*)&wk : &bk;
      }
      default: return nullptr;
    }
  }

  char piece_char(const piece_t* piece) {
      if(piece == nullptr)
        return '.';
      constexpr std::string_view letters = ".PNBRQK";
      const char letter = letters[static_cast<std::size_t>(piece->type)];
      if(piece->color == color_t::BLACK)
        return static_cast<char>(std::tolower(letter));
      return letter;
  }

} // namespace

board_t::board_t()
  : squares(square_count, nullptr),
    side_to_move(color_t::WHITE) {
  set_starting_position();
}

void board_t::set_starting_position() {
  squares.assign(square_count, nullptr);

  const type_t back_rank[8]
    = {type_t::ROOK, type_t::KNIGHT, type_t::BISHOP, type_t::QUEEN,
       type_t::KING, type_t::BISHOP, type_t::KNIGHT, type_t::ROOK};

  for(int file = 0; file < 8; ++file) {
    squares[square_index(file, 0)] = get_piece(color_t::WHITE, back_rank[file]);
    squares[square_index(file, 1)] = get_piece(color_t::WHITE, type_t::PAWN);
    squares[square_index(file, 6)] = get_piece(color_t::BLACK, type_t::PAWN);
    squares[square_index(file, 7)] = get_piece(color_t::BLACK, back_rank[file]);
  }

  side_to_move = color_t::WHITE;
}

bool board_t::apply_move(const move_t &m) {
  if(!is_valid_square(m.from) || !is_valid_square(m.to))
    return false;

  const piece_t* moving = squares[m.from];
  if(moving == nullptr || moving->color != side_to_move)
    return false;

  if(m.promotion != type_t::EMPTY)                 
    moving = get_piece(moving->color, m.promotion);

  squares[m.to] = moving;
  squares[m.from] = nullptr;

  side_to_move
    = side_to_move == color_t::WHITE ? color_t::BLACK : color_t::WHITE;
  return true;
}

std::string board_t::to_string() const {
  std::string text;
  for(int rank = 7; rank >= 0; --rank) {
    text += static_cast<char>('1' + rank);
    text += ' ';
    for(int file = 0; file < 8; ++file) {
      text += piece_char(squares[square_index(file, rank)]);
      text += ' ';
    }
    text += '\n';
  }
  text += "  a b c d e f g h\n";
  return text;
}

std::vector<move_t> board_t::pseudo_legal_moves() const {
    std::vector<move_t> moves;
    for ( int sq = 0; sq < square_count; sq++ ) {
      const piece_t* piece = squares[sq];
      if ( piece == nullptr || piece->color != side_to_move ) {
        continue;
      }
      std::vector<move_t> piece_moves = piece->get_moves(*this, sq);
      moves.insert(moves.end(), piece_moves.begin(), piece_moves.end());
    }
    return moves;
}