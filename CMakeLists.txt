cmake_minimum_required(VERSION 3.1...3.28)

project(
  ModernCMakeExample
  VERSION 1.0
  LANGUAGES CXX)

find_package(Qt5Sql REQUIRED)


add_executable(character character.cpp)
target_link_libraries(character  Qt5::Core Qt5::Sql)

