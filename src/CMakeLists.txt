file(GLOB SOURCES *.cpp)
add_executable(main ${SOURCES} main.cpp)
target_link_libraries(main ${CONAN_LIBS}) # How to avoid gtest?
