cmake_minimum_required(VERSION 3.10)

project(OpenDMARC VERSION 1.4.1)

# don't know if we use C17 features, so this might change to something older
set(C_STANDARD 17)
set(C_STANDARD_REQUIRED yes)

add_subdirectory(libopendmarc)
add_subdirectory(opendmarc)

target_include_directories(libopendmarc PUBLIC
    "${PROJECT_BINARY_DIR}"
)

configure_file(opendmarc_conf.h.in opendmarc_conf.h)

#target_link_libraries(opendmarc spf2 milter pthread)
