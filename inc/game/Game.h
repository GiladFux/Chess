#pragma once

#include "UIManager.h"
#include "Board.h"

class Game
{

public:
    Game();

    void run();

private: 
    Board m_board;
    UI m_ui;

};
