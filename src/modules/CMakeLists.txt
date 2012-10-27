file(GLOB_RECURSE moduleSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.h)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LIBXML2_INCLUDE_DIR}
    ${CURL_INCLUDE_DIR}
)

add_library(modules STATIC
    ${moduleSources}
)

target_link_libraries(modules
    ${LIBXML2_LIBRARIES}
    ${CURL_LIBRARIES}
)
