cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set (SOURCE_FILES main.cpp GameCharacter.cpp GameCharacter.h DynamicComponent.cpp DynamicComponent.h StaticComponent.cpp StaticComponent.h Weapon.cpp Weapon.h Player.cpp Player.h Game.cpp Game.h Enemy.cpp Enemy.h Subject.h CollisionObserver.h Factory.cpp Factory.h PlayerWeapon.cpp PlayerWeapon.h Inventory.cpp Inventory.h HUD.cpp HUD.h MenuState.cpp MenuState.h GameOverState.cpp GameOverState.h Text.cpp Text.h GameState.cpp GameState.h State.h StateMachine.cpp StateMachine.h PauseState.cpp PauseState.h Def.h SplashState.cpp SplashState.h Strategy.h Follow.cpp Follow.h RandomMove.cpp RandomMove.h Static.h Sprite.cpp Sprite.h TileMap.cpp TileMap.h Room.cpp Room.h Professor.cpp Professor.h Token.cpp Token.h)

add_executable(game ${SOURCE_FILES} )
add_library( core ${SOURCE_FILES} )
target_link_libraries(game core)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries( game ${SFML_LIBRARIES})
endif()
