cmake_minimum_required(VERSION 3.14)

add_subdirectory(./lib/googletest)
set (gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTests.cpp CollisionTest.cpp StrategyTest.cpp RandomSpawnTest.cpp WeaponDirectionTest.cpp TileMapCollisionTest.cpp BadgeTest.cpp)
add_executable(runAllTests ${SOURCE_TEST_FILES})
target_link_libraries(runAllTests gtest gtest_main core)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries( runAllTests ${SFML_LIBRARIES})
endif()