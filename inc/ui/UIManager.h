#pragma once

#include "Board.h"
#include <SDL3/SDL.h>
#include <array>

class UI {
public:
  UI();
  UI(Board *board);
  ~UI();

  void displayBoard(SDL_Renderer *renderer);
  bool getMove(Position &from, Position &to); // returns false if quit

private:
  void loadTextures(SDL_Renderer *renderer);
  void destroyTextures();

  Board *m_board;
  SDL_Renderer *m_textureRenderer;
  std::array<SDL_Texture *, 12> m_pieceTextures;
};