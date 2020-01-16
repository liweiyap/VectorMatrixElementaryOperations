include_directories("${PROJECT_SOURCE_DIR}/headers")

set(LIBS
    myVector
    auxiliary
    myColumnVector
    myMatrix
    myRowVector
    moreVectorMatrixOps
)

foreach(LIB ${LIBS})
    add_library(${LIB} ${LIB}.cpp)
endforeach()