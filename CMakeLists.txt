cmake_minimum_required(VERSION 3.0.0)

project ("fondamenti-ii")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}" CACHE PATH "Install prefix" FORCE)

if(MSVC)
 set(CMAKE_USE_RELATIVE_PATHS ON CACHE INTERNAL "" FORCE)
endif()

if(DEFINED CMAKE_BUILD_TYPE)
 set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${CMAKE_CONFIGURATION_TYPES})
endif()

set(SUB_DIRS "list" "tree" "minheap")
# message(STATUS ${SUB_DIRS})

FOREACH(cur_dir ${SUB_DIRS})
	# message(STATUS "cur_dir: ${cur_dir}")
    file(GLOB sub_sub_dirs "${cur_dir}/*")
    FOREACH(cur_sub_dir ${sub_sub_dirs})
		
		get_filename_component(dir_name "${cur_sub_dir}" NAME)
		# message(STATUS "dir_name: ${dir_name}")		
		if(IS_DIRECTORY ${cur_sub_dir} AND NOT ${dir_name} STREQUAL "doxygen")
			# message(STATUS "cur_sub_dir: ${cur_sub_dir}")		
			
			# get_filename_component(dir_name "${cur_sub_dir}" NAME)
			set(target_name "${cur_dir}_${dir_name}")
			string(TOUPPER ${target_name} target_name_uppercase)
			
			# file(GLOB sources ${cur_sub_dir}/*.c)
			# file(GLOB headers ${cur_sub_dir}/*.h)	
			
			# add_library(${target_name_uppercase} STATIC ${sources} ${headers})
			add_library(${target_name_uppercase})
			
			target_sources(${target_name_uppercase}
				PRIVATE
						${cur_sub_dir}/../${cur_dir}.h
						${cur_sub_dir}/../${cur_dir}.c
					elemtype/${dir_name}/elemtype.h
					elemtype/${dir_name}/elemtype.c
			)

			target_include_directories(${target_name_uppercase} PUBLIC ${cur_sub_dir}/../)
			target_include_directories(${target_name_uppercase} PUBLIC ${cur_sub_dir}/../../elemtype/${dir_name}/)
		
			set(cur_folder "${cur_dir}/${dir_name}")
			set_target_properties(${target_name_uppercase} PROPERTIES FOLDER ${cur_folder}) # Set target folder

			# Add examples
			if(EXISTS ${cur_sub_dir}/examples)
				add_subdirectory(${cur_sub_dir}/examples)
			endif()
		endif()
    ENDFOREACH()
ENDFOREACH()