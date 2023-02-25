add_library(rollback SHARED rollback.cpp)

target_include_directories(rollback PUBLIC ${ROLLBACK_INC_DIR})
