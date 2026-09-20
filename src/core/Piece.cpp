#include "Piece.h"


Piece::Piece(PieceType t, bool white) {
    type = t;
    isWhiteFlag = white;
}

Piece::~Piece() {}

PieceType Piece::getType() const {
    return type;
}

bool Piece::isWhite() const {
    return isWhiteFlag;
}

void Piece::setType(PieceType t) {
    type = t;
}