project('Clock', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

inc_dir = include_directories(['include',
                               get_option('cli11_include_dir'),
#                               get_option('spdlog_include_dir'),
#                               get_option('json_include_dir'),
#                               get_option('asio_include_dir')                               
                              ])

#subdir('XXX')

src = ['src/main.cpp', 'src/Clock.cpp', 'src/TimeSlave.cpp', 'src/TimeMaster.cpp', 'src/Channel.cpp']

executable('clock',
            sources : src,
            include_directories : inc_dir,
            dependencies : thread_dep,
            #link_with : XXX_lib
           )