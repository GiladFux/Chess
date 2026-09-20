#include "Piece.h"

class Knight : public Piece {
public:
    Knight(bool isWhite);
    ~Knight();
    bool isValidMove(Position fromPosition, Position toPosition) const override;
};
