set (module_name lily_matrix)
message(STATUS "${module_name}")
message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}: ${OpenCV_LIBS}")

include_directories(../includes)

#FILE(GLOB sourcefiles "*.cpp" "*.c")
FILE(GLOB_RECURSE sourcefiles "*.cpp" "*.c")
#FILE(GLOB_RECURSE sourcefiles "src/connectedCompents.cpp")
#target_link_libraries(k ${VISION_BASE} ${LI_OpenCV_LIBS})

#FILE(GLOB sourcefiles "src/*.cpp" "src/*.c")
#add_library(${module_name} SHARED ${sourcefiles})
add_library(${module_name} STATIC ${sourcefiles})

#target_link_libraries(${module_name} vision_video ${LI_OpenCV_LIBS})
target_link_libraries(${module_name} ${LI_OpenCV_LIBS})

install (TARGETS ${module_name}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

