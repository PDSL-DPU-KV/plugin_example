#include "hello_plugin_interface.hh"
#include "plugin.hh"

#include <iostream>

auto main() -> int {
  try {
    std::string plugin_prefix = "./build/example/src/libhello_plugin";
#if __linux__
    std::string plugin_suffix = ".so";
#elif __APPLE__
    std::string plugin_suffix = ".dylib";
#else
#error "I'm sorry!"
#endif

    int id = 0;
    while (true) {
      std::cout << "Load which plugin(1 or 2): ";
      std::cin >> id;

      if (id != 1 and id != 2) {
        return 0;
      }

      auto plugin_name = plugin_prefix + std::to_string(id) + plugin_suffix;

      plugin::Loader<example::AppHelloPluginInterface> loader(plugin_name);

      std::cout << "Load Plugin: " << loader.get_name() << std::endl
                << "Plugin Author: " << loader.get_author() << std::endl
                << "Plugin Version: " << loader.get_version() << std::endl;

      std::cout << "=== Trigger Plugin Method Begin ===" << std::endl;
      loader->say_hello();
      std::cout << "=== Trigger Plugin Method End ===" << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}