#include "Piece.h"

class Queen : public Piece {
public:
    Queen(bool isWhite);
    ~Queen();
    bool isValidMove(Position fromPosition, Position toPosition) const override;
};
