add_library(chess_core
    Bishop.cpp
    Board.cpp
    King.cpp
    Knight.cpp
    Pawn.cpp
    Piece.cpp
    Queen.cpp
    Rook.cpp
)

target_include_directories(chess_core PUBLIC
    ${PROJECT_SOURCE_DIR}/inc/core
)