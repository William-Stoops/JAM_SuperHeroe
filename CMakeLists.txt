cmake_minimum_required(VERSION 3.0.0)

project(EpitechJam LANGUAGES CXX)

include_directories(includes)

include(FetchContent)
FetchContent_Declare(SFML        GIT_REPOSITORY https://github.com/SFML/SFML.git        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(EpitechJam
        src/SFML/Sfml.cpp
        src/main.cpp
        src/Character.cpp
        src/game_over.cpp
        src/class/Game.cpp
        src/class/Mob.cpp
        src/class/Projectile.cpp
        src/class/Hud.cpp src/class/Exp.cpp src/class/Exp.hpp
        src/start.cpp)

target_link_libraries(EpitechJam PRIVATE sfml-window sfml-system sfml-audio sfml-graphics)

target_compile_features(EpitechJam PRIVATE cxx_std_20)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET EpitechJam POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:EpitechJam> $<TARGET_FILE_DIR:EpitechJam> COMMAND_EXPAND_LISTS)
endif ()

install(TARGETS EpitechJam)
