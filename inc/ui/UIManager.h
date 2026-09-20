#pragma once

#include "Board.h"

class UI{

    public:
        UI();
        UI(Board* board);
        ~UI();
        void displayBoard();
        bool getMove(Position& from, Position& to);  // returns false if quit

    private:
    Board* m_board;
};