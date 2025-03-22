cmake_minimum_required(VERSION 3.21)

PROJECT(mh_p1 CXX)

file(GLOB C_SOURCES
  "src/*.cpp"
  "common/*.cpp"
)
INCLUDE_DIRECTORIES("common" "inc")

ADD_EXECUTABLE(main "main.cpp" ${C_SOURCES})
