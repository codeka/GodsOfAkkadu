TARGET_SOURCES (${PROJECT_NAME}
    PRIVATE
        register_types.cc
        register_types.h
        terrain/terrain3d.cc
        terrain/terrain3d.h
)

TARGET_INCLUDE_DIRECTORIES (${PROJECT_NAME}
    PRIVATE
        "src"
)
