#pragma once

enum PieceType {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

struct Position{
    int x;
    int y;

    bool operator==(const Position& other)const {
        return ((x == other.x) && (y == other.y));
    }
};

class Piece {
public:

    Piece(PieceType type, bool white);
    ~Piece();

    virtual bool isValidMove(Position fromPosition, Position toPosition) const = 0;

    PieceType getType() const;
    bool isWhite() const;
    void setType(PieceType type);

private:
    PieceType type;
    bool isWhiteFlag;
};