include_directories(AFTER ${MICHET_INCLUDE_DIRS})

set(MICHET_SRC_FILES
michet.c
)

set(MICHET_LINK_LIBRARIES
#${MICHET_LIBRARY}
)

add_executable(michet ${MICHET_SRC_FILES})
target_link_libraries(michet ${MICHET_LINK_LIBRARIES})
