#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(bool isWhite);
    ~Pawn();
    bool isValidMove(Position fromPosition, Position toPosition) const override;
};
