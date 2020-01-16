cmake_minimum_required(VERSION 2.8)
project(ATLATEC)

set(CMAKE_CXX_STANDARD 17)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(include)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_lambdas)
target_link_libraries(main myVector)
target_link_libraries(main auxiliary)
target_link_libraries(main myColumnVector)
target_link_libraries(main myMatrix)
target_link_libraries(main myRowVector)
target_link_libraries(main moreVectorMatrixOps)

include_directories("${PROJECT_SOURCE_DIR}/tests")