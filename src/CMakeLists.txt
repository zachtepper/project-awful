#Cmake version
cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# set the project name
project(awful VERSION 1.0)

# add the executable
add_executable(awful awful.cpp Game.cpp 
                State/State.cpp State/MainMenuState.cpp State/GameState.cpp State/CharacterState.cpp State/SettingsState.cpp
                Actor/Actor.cpp Actor/Player.cpp Actor/Enemy.cpp
                Ancilla/Ancilla.cpp Ancilla/Sword.cpp
                Components/MovementComponent.cpp Components/HitboxComponent.cpp Components/AnimationComponent.cpp
                World/World.cpp World/Overworld.cpp World/Underworld.cpp
                Dungeon/DungeonGenerator.cpp Dungeon/Dungeon.cpp Dungeon/Subdungeon.cpp Dungeon/Room.cpp
                GUI/Text.cpp GUI/Textbox.cpp  GUI/Button.cpp  GUI/PauseMenu.cpp GUI/DropDown.cpp )
include_directories("../assets")

# find the sfml library 
find_package(SFML 2.5 COMPONENTS graphics audio network system audio REQUIRED)
target_link_libraries(awful sfml-graphics sfml-audio sfml-network sfml-system sfml-audio)

set (source "${CMAKE_SOURCE_DIR}/assets")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/assets")
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination} 
    DEPENDS ${destination}
    COMMENT "symbolic link resources folder from ${source} => ${destination}"
)
