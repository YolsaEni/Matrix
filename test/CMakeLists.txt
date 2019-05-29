include_directories(.)

set (module_name lily_matrix_test)
message(STATUS "${module_name}")

FILE(GLOB sourcefiles "*.cpp" "*.c")
#FILE(GLOB_RECURSE sourcefiles "src/connectedCompents.cpp")
#target_link_libraries(k ${VISION_BASE} ${LI_OpenCV_LIBS})

#FILE(GLOB sourcefiles "src/*.cpp" "src/*.c")
add_executable(${module_name} ${sourcefiles})
target_link_libraries(${module_name} lily_matrix ${LI_OpenCV_LIBS})
#target_link_libraries(${module_name} vision_video vision_meter ${LI_OpenCV_LIBS})

install (TARGETS ${module_name}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
