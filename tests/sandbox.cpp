#include "board.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {

void print_moves(std::ostream& out, const board_t& board) {
  out << board.to_string() << '\n';

  const std::vector<move_t> moves = board.pseudo_legal_moves();
  out << moves.size() << " moves:\n";
  for(const move_t& m : moves)
    out << m.to_uci() << ' ';
  out << "\n\n";
}

}

int main(int argc, char* argv[]) {
  const std::string path = (argc > 1) ? argv[1] : "runtime/test.txt";
  std::ofstream out(path);
  if(!out) {
    std::cerr << "Error: cannot write to " << path << '\n';
    return 1;
  }

  // ===== put your test code below =====

  board_t board;
  out << "--- starting position ---\n";
  print_moves(out, board);

  board.apply_move(move_t::from_uci("e2e4"));
  board.apply_move(move_t::from_uci("d7d5"));
  out << "--- after e2e4 d7d5 ---\n";
  print_moves(out, board);

  // ===== end of test code =====

  std::cout << "Wrote " << path << '\n';
  return 0;
}
