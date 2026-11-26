#pragma once

#include <array>
#include <string>

enum class color_t { 
	WHITE, BLACK
};

enum class type_t {
  EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

constexpr int SquareCount = 64;

constexpr int squareIndex(int file, int rank) {
  return rank * 8 + file;
}

constexpr bool isValidSquare(int square) {
  return square >= 0 && square < SquareCount;
}

constexpr color_t colorOf(piece_t piece) {
  return piece >= Piece::BlackPawn ? Color::Black : Color::White;
}

class Board {
public:
  Board();

  void setStartingPosition();
  bool applyMove(int from, int to);
  std::string toString() const;

  piece_t pieceAt(int square) const {
    return squares_[square];
  }

  color_t sideToMove() const {
    return sideToMove_;
  }

private:
  std::array<Piece, SquareCount> squares_{};
  Color sideToMove_ = Color::White;
};
