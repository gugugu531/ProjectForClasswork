cmake_minimum_required (VERSION 3.10)
 
project (learn_cmake)
 
include_directories(./include)

aux_source_directory(src_dir SRC_LIST1)
aux_source_directory(main_dir MAIN_DIR)

add_executable(project ${SRC_LIST1} ${MAIN_DIR} )