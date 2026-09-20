#include "Board.h"

Board::Board() {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            squares[y][x] = nullptr;
        }
    }

    // White back rank
    squares[7][0] = new Rook(true);
    squares[7][1] = new Knight(true);
    squares[7][2] = new Bishop(true);
    squares[7][3] = new Queen(true);
    squares[7][4] = new King(true);
    squares[7][5] = new Bishop(true);
    squares[7][6] = new Knight(true);
    squares[7][7] = new Rook(true);

    // White pawns
    for (int x = 0; x < 8; ++x) {
        squares[6][x] = new Pawn(true);
    }

    // Black back rank
    squares[0][0] = new Rook(false);
    squares[0][1] = new Knight(false);
    squares[0][2] = new Bishop(false);
    squares[0][3] = new Queen(false);
    squares[0][4] = new King(false);
    squares[0][5] = new Bishop(false);
    squares[0][6] = new Knight(false);
    squares[0][7] = new Rook(false);

    // Black pawns
    for (int x = 0; x < 8; ++x) {
        squares[1][x] = new Pawn(false);
    }
}

Board::~Board() {
    for (int y = 0; y < 8; ++y) {
        for (int x = 0; x < 8; ++x) {
            delete squares[y][x];
            squares[y][x] = nullptr;
        }
    }
}

Piece* Board::getPieceAt(int x, int y) const {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return nullptr;
    }

    return squares[y][x];
}

void Board::setPieceAt(int x, int y, Piece* piece) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return;
    }

    squares[y][x] = piece;
}
