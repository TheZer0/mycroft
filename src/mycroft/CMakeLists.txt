file(GLOB_RECURSE mycroftSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.h)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/modules
)

add_executable(mycroft ${mycroftSources})

target_link_libraries(mycroft
    modules)
