add_executable(test test.cpp)
target_link_libraries(test PRIVATE rollback)

add_executable(server test_server.cpp)
target_link_libraries(server PRIVATE rollback)
