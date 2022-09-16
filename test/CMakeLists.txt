file(GLOB SOURCES *.cpp)
add_executable(Test main.cpp)
target_link_libraries(Test ${CONAN_LIBS})
add_test(NAME tests COMMAND Test)
