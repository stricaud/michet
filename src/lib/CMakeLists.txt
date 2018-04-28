include_directories(AFTER ${MICHET_INCLUDE_DIRS})

bison_target(generatorparser generators.y ${CMAKE_CURRENT_BINARY_DIR}/generators.tab.c)
flex_target(generatorscanner generators.l ${CMAKE_CURRENT_BINARY_DIR}/lex.generators.c)
add_flex_bison_dependency(generatorscanner generatorparser)

set(LIBMICHET_SRC_FILES
  michet.c
  write-asm.c
  ${BISON_generatorparser_OUTPUTS}
  ${FLEX_generatorscanner_OUTPUTS}
)

add_library(michet SHARED ${LIBMICHET_SRC_FILES})
target_link_libraries(michet)
