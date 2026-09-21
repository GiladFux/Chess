add_library(chess_ui
    UIManager.cpp
)

target_include_directories(chess_ui PUBLIC
    ${PROJECT_SOURCE_DIR}/inc/ui
)

target_compile_definitions(chess_ui PRIVATE
    CHESS_ASSETS_DIR="${PROJECT_SOURCE_DIR}/assets"
)

target_link_libraries(chess_ui PUBLIC
    chess_core
    SDL3::SDL3
)