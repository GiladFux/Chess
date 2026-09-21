add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(game)

add_executable(chess
    main.cpp
)

target_link_libraries(chess PRIVATE
    chess_game
    SDL3::SDL3
)