add_library(chess_game
    Game.cpp
)

target_include_directories(chess_game PUBLIC
    ${PROJECT_SOURCE_DIR}/inc/game
    ${PROJECT_SOURCE_DIR}/inc/ui
)

target_link_libraries(chess_game PUBLIC
    chess_core
    chess_ui
)