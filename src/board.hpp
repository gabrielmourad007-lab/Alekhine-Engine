#pragma once

#include <array>
#include <string>

enum class Color { White, Black };

enum class Piece {
  Empty,
  WhitePawn,
  WhiteKnight,
  WhiteBishop,
  WhiteRook,
  WhiteQueen,
  WhiteKing,
  BlackPawn,
  BlackKnight,
  BlackBishop,
  BlackRook,
  BlackQueen,
  BlackKing
};

constexpr int SquareCount = 64;

constexpr int squareIndex(int file, int rank) {
  return rank * 8 + file;
}

constexpr bool isValidSquare(int square) {
  return square >= 0 && square < SquareCount;
}

constexpr Color colorOf(Piece piece) {
  return piece >= Piece::BlackPawn ? Color::Black : Color::White;
}

class Board {
public:
  Board();

  void setStartingPosition();
  bool applyMove(int from, int to);
  std::string toString() const;

  Piece pieceAt(int square) const {
    return squares_[square];
  }

  Color sideToMove() const {
    return sideToMove_;
  }

private:
  std::array<Piece, SquareCount> squares_{};
  Color sideToMove_ = Color::White;
};
