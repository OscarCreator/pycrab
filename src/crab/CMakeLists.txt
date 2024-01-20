set(SRC_CRAB
    point.c
    crab.c
)
set(HEADERS_CRAB
    ${CMAKE_CURRENT_SOURCE_DIR}/point.h
    ${CMAKE_CURRENT_SOURCE_DIR}/crab.h
    PARENT_SCOPE
)

foreach(src ${SRC_CRAB})
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/${src})
endforeach()

set(SOURCES ${SOURCES} PARENT_SCOPE)
