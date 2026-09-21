#include "UIManager.h"
#include <string>

#ifndef CHESS_ASSETS_DIR
#define CHESS_ASSETS_DIR "assets"
#endif

namespace {
constexpr int BOARD_SIZE = 8;
constexpr int TILE_SIZE = 80;

int textureIndex(bool isWhite, PieceType type) {
  return (isWhite ? 0 : 6) + static_cast<int>(type);
}

const char *pieceName(PieceType type) {
  switch (type) {
  case PAWN:
    return "Pawn";
  case ROOK:
    return "Rook";
  case KNIGHT:
    return "Knight";
  case BISHOP:
    return "Bishop";
  case QUEEN:
    return "Queen";
  case KING:
    return "King";
  default:
    return nullptr;
  }
}

SDL_Color getTileColor(int x, int y) {
  return (x + y) % 2 == 0 ? SDL_Color{238, 238, 210, 255}
                          : SDL_Color{118, 150, 86, 255};
}

SDL_Color getPieceColor(bool isWhite) {
  return isWhite ? SDL_Color{255, 255, 255, 255} : SDL_Color{20, 20, 20, 255};
}
} // namespace

UI::UI() : m_board(nullptr), m_textureRenderer(nullptr), m_pieceTextures{} {}
UI::UI(Board *board)
    : m_board(board), m_textureRenderer(nullptr), m_pieceTextures{} {}

UI::~UI() { destroyTextures(); }

void UI::destroyTextures() {
  for (SDL_Texture *&texture : m_pieceTextures) {
    if (texture != nullptr) {
      SDL_DestroyTexture(texture);
      texture = nullptr;
    }
  }
  m_textureRenderer = nullptr;
}

void UI::loadTextures(SDL_Renderer *renderer) {
  if (renderer == nullptr || renderer == m_textureRenderer) {
    return;
  }

  destroyTextures();
  m_textureRenderer = renderer;

  for (int color = 0; color < 2; ++color) {
    for (int type = 0; type < 6; ++type) {
      const char *name = pieceName(static_cast<PieceType>(type));
      const char *prefix = color == 0 ? "W_" : "B_";
      const std::string path = std::string(CHESS_ASSETS_DIR) +
                               "/16x32 pieces/" + prefix + name + ".png";

      SDL_Surface *surface = SDL_LoadPNG(path.c_str());
      SDL_Texture *texture =
          surface == nullptr ? nullptr
                             : SDL_CreateTextureFromSurface(renderer, surface);
      if (surface != nullptr) {
        SDL_DestroySurface(surface);
      }
      if (texture == nullptr) {
        SDL_Log("Could not load piece asset %s: %s", path.c_str(),
                SDL_GetError());
      }
      m_pieceTextures[color * 6 + type] = texture;
    }
  }
}

void UI::displayBoard(SDL_Renderer *renderer) {
  if (renderer == nullptr) {
    return;
  }

  loadTextures(renderer);

  for (int y = 0; y < BOARD_SIZE; ++y) {
    for (int x = 0; x < BOARD_SIZE; ++x) {
      const SDL_Color tile = getTileColor(x, y);
      SDL_SetRenderDrawColor(renderer, tile.r, tile.g, tile.b, tile.a);

      SDL_FRect rect = {
          static_cast<float>(x * TILE_SIZE), static_cast<float>(y * TILE_SIZE),
          static_cast<float>(TILE_SIZE), static_cast<float>(TILE_SIZE)};
      SDL_RenderFillRect(renderer, &rect);
    }
  }

  if (m_board == nullptr) {
    return;
  }

  for (int y = 0; y < BOARD_SIZE; ++y) {
    for (int x = 0; x < BOARD_SIZE; ++x) {
      Piece *piece = m_board->getPieceAt(x, y);
      if (piece == nullptr) {
        continue;
      }

      SDL_Texture *texture =
          m_pieceTextures[textureIndex(piece->isWhite(), piece->getType())];
      SDL_FRect destination = {
          static_cast<float>(x * TILE_SIZE), static_cast<float>(y * TILE_SIZE),
          static_cast<float>(TILE_SIZE), static_cast<float>(TILE_SIZE)};

      if (texture != nullptr) {
        SDL_RenderTexture(renderer, texture, nullptr, &destination);
      } else {
        const SDL_Color pieceColor = getPieceColor(piece->isWhite());
        SDL_SetRenderDrawColor(renderer, pieceColor.r, pieceColor.g,
                               pieceColor.b, pieceColor.a);
        SDL_RenderFillRect(renderer, &destination);
      }
    }
  }
}

bool UI::getMove(Position &from, Position &to) {
  (void)from;
  (void)to;
  return true;
}
