#ifndef _BOARD_H_
#define _BOARD_H_

#include "constants.h"
#include "piece.h"
#include "move.h"

#include <string>
#include <vector>

constexpr int square_count = 64;

constexpr int file_of(int sq) {
  return sq % 8;
}

constexpr int rank_of(int sq) {
  return sq / 8;
}

constexpr int square_index(int file, int rank) {
  return rank * 8 + file;
}

constexpr bool is_valid_square(int square) {
  return square >= 0 && square < square_count;
}

class board_t {
public:
  std::vector<const piece_t*> squares;
  color_t side_to_move;

  board_t();

  void set_starting_position();
  std::string to_string() const;
  bool apply_move(const move_t &m);

  std::vector<move_t> pseudo_legal_moves() const;
  std::vector<move_t> legal_moves() const;
  bool is_square_attacked(int sq, color_t by) const;
  int find_king(color_t color) const;
};
#endif
