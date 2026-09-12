# Build rules for `solve/`.
#
# New solutions added under `solutions/<site>/<level>/<Problem>.{h,cpp}` are
# picked up automatically. New tests under `tests/<site>/<level>/` become
# one ctest binary each, linked only with the sources they need.

# --- collect solution / util sources ---
file(GLOB_RECURSE SOLUTION_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/solutions/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/util/*.cpp")

# --- judge (manual debug entry) ---
add_executable(judge
        judge.cpp
        ${SOLUTION_SOURCES})
target_include_directories(judge PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})