cmake_minimum_required(VERSION 3.10)

project(OpenDMARC VERSION 1.4.1)

# don't know if we use C17 features, so this might change to something older
set(C_STANDARD 17)
set(C_STANDARD_REQUIRED yes)

add_executable(opendmarc)

target_include_directories(opendmarc PUBLIC
    "${PROJECT_BINARY_DIR}"
)

configure_file(opendmarc.h.in opendmarc.h)

target_link_libraries(opendmarc spf2 milter pthread)
