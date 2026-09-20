#include "Piece.h"

class King : public Piece {
public:
    King(bool isWhite);
    ~King();
    bool isValidMove(Position fromPosition, Position toPosition) const override;
};