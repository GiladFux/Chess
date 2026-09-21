#include <iostream>

#include "Game.h"

typedef enum MAIN_res_e {
  MAIN_RES_SUCCESS,
  MAIn_RES_FAILED,
} MAIN_res_t;

int main(void) {

  Game *game = new Game();
  game->run();

  return MAIN_RES_SUCCESS;
}