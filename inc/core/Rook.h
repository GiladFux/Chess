#include "Piece.h"

class Rook : public Piece {
public:
    Rook(bool isWhite);
    ~Rook();
    bool isValidMove(Position fromPosition, Position toPosition) const override;
};
