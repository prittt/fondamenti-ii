set(examples_sources
    insert_ord.c
    iterate.c
)
FOREACH(cur_file ${examples_sources})
    get_filename_component(exe_name ${cur_file} NAME_WE)
    set(cur_file "examples/${cur_file}")
    add_executable(${exe_name} ${cur_file})
    set_target_properties(${exe_name} PROPERTIES FOLDER "Examples")
    target_link_libraries(${exe_name} ${ECVL_MODULES})
ENDFOREACH()