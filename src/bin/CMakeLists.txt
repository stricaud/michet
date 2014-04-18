include_directories(AFTER ${MICHET_INCLUDE_DIRS})

set(MICHET_SRC_FILES
mic.c
)

set(MICHET_LINK_LIBRARIES
${MICHET_LIBRARY}
)

add_executable(mic ${MICHET_SRC_FILES})
target_link_libraries(mic ${MICHET_LINK_LIBRARIES})
