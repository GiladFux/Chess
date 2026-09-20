#pragma once

#include "Piece.h"
#include "Rook.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"

class Board
{
    public:
        Board();
        ~Board();

        Piece* getPieceAt(int x, int y) const;
        void setPieceAt(int x, int y, Piece* piece);

    private:
        Piece* squares[8][8];
};