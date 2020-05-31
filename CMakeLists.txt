cmake_minimum_required(VERSION 3.0.0)

project ("Fondamenti-II")

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE PATH "Install prefix" FORCE)

if(MSVC)
 set(CMAKE_USE_RELATIVE_PATHS ON CACHE INTERNAL "" FORCE)
endif()

if(DEFINED CMAKE_BUILD_TYPE)
 set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
endif()

set(SUB_DIRS "list" "tree" "min-heap")
# message(STATUS ${SUB_DIRS})

FOREACH(cur_dir ${SUB_DIRS})
	# message(STATUS ${cur_dir})
    file(GLOB sub_sub_dirs "${cur_dir}/*")
    FOREACH(cur_sub_dir ${sub_sub_dirs})
		
		get_filename_component(dir_name "${cur_sub_dir}" NAME)
		set(target_name "${cur_dir}_${dir_name}")
		string(TOUPPER ${target_name} target_name_uppercase)
		
		file(GLOB sources ${cur_sub_dir}/*.c)
		file(GLOB headers ${cur_sub_dir}/*.h)
		add_library(${target_name_uppercase} STATIC ${sources} ${headers})
		target_include_directories(${target_name_uppercase} PUBLIC ${cur_sub_dir})
	
		if(EXISTS ${cur_sub_dir}/examples)
			add_subdirectory(${cur_sub_dir}/examples)
		endif()
    ENDFOREACH()
ENDFOREACH()