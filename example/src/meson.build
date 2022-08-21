hello_from_here_plugin = shared_library(
    'hello_plugin1',
    'hello_from_here_impl.cc',
    include_directories: hello_plugin_include_directories,
)

hello_from_there_plugin = shared_library(
    'hello_plugin2',
    'hello_from_there_impl.cc',
    include_directories: hello_plugin_include_directories,
)

message(hello_from_here_plugin.full_path())
message(hello_from_there_plugin.full_path())
