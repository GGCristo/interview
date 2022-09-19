file(GLOB SOURCES CONFIGURE_DEPENDS *.cpp ${CMAKE_SOURCE_DIR}/src/*.cpp)
# set(SOURCES
#     ../src/doctor.cpp
#     ../src/person.cpp
#     ../src/patient.cpp
#     ../src/registry.cpp
#     ../src/combGenerator.cpp
#     registry.cpp
#     personTest.cpp
#     waitingListTest.cpp
# )
list(REMOVE_ITEM SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")
add_executable(Test ${SOURCES})
target_include_directories(Test PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Test ${CONAN_LIBS})
add_test(NAME tests COMMAND Test)
