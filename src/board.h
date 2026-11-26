#ifndef _BOARD_H_
#define _BOARD_H_

#include "constants.h"
#include "piece.h"

#include <string>
#include <vector>

constexpr int square_count = 64;

constexpr int square_index(int file, int rank) {
  return rank * 8 + file;
}

constexpr bool is_valid_square(int square) {
  return square >= 0 && square < square_count;
}

class board_t {
public:
  std::vector<piece_t> squares;
  color_t side_to_move;

  board_t();

  void set_starting_position();
  bool apply_move(int from, int to);
  std::string to_string() const;
};

#endif
