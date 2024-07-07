
CMAKE_MINIMUM_REQUIRED (VERSION 3.22)
MESSAGE (STATUS "Using CMake ${CMAKE_VERSION}")


# Turn on link time optimization for everything
SET (CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

# Output compile commands to compile_commands.json (for debugging CMake issues)
SET (CMAKE_EXPORT_COMPILE_COMMANDS ON)

PROJECT (GodsOfAkkadu
    LANGUAGES
        CXX
    VERSION
        0.1.0
)

ADD_LIBRARY (${PROJECT_NAME} SHARED)

SET_TARGET_PROPERTIES	 (${PROJECT_NAME}
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden
        VISIBILITY_INLINES_HIDDEN true
				CXX_STANDARD 23
)

ADD_SUBDIRECTORY (src)

SET (INSTALL_DIR "${CMAKE_SOURCE_DIR}/game/bin/windows/")
MESSAGE (STATUS "Install directory: ${INSTALL_DIR}")

INSTALL (TARGETS ${PROJECT_NAME}
    LIBRARY
        DESTINATION ${INSTALL_DIR}/${LIB_DIR}
    RUNTIME
        DESTINATION ${INSTALL_DIR}/${LIB_DIR}
)

ADD_SUBDIRECTORY (godot-cpp)

SET_TARGET_PROPERTIES (godot-cpp
    PROPERTIES
        CXX_VISIBILITY_PRESET hidden    # visibility needs to be the same as the main library
)

TARGET_LINK_LIBRARIES (${PROJECT_NAME}
    PRIVATE
        godot-cpp
)
