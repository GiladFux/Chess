#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(bool isWhite);
    ~Bishop();
    bool isValidMove(Position fromPosition, Position toPosition) const override;
};