include_directories(AFTER ${MICHET_INCLUDE_DIRS})

set(LIBMICHET_SRC_FILES
michet.c
write-asm.c
)

add_library(michet SHARED ${LIBMICHET_SRC_FILES})
target_link_libraries(michet)
