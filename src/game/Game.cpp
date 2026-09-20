#include "Game.h"

Game::Game() : m_ui(&m_board){}

void Game::run(){
    while (true)
    {
        m_ui.displayBoard();
    }
}