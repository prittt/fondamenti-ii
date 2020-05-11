set(examples_sources
    iterate.c
)
FOREACH(cur_file ${examples_sources})
    get_filename_component(exe_name ${cur_file} NAME_WE)
	set(exe_name "${target_name_uppercase}_${exe_name}")
	
    add_executable(${exe_name} ${cur_file})
    set_target_properties(${exe_name} PROPERTIES FOLDER "examples")
    target_link_libraries(${exe_name} ${target_name_uppercase})
ENDFOREACH()