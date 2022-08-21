#pragma once

#include <functional>

namespace plugin {

template <typename Interface> class ExportMeta {
  using instance_handler_t = Interface *(*)();

public:
  instance_handler_t get_instance_;
  const char *name_;
  const char *version_;
  const char *author_;
};

#define PlugIn(plugin_name, plugin_interface, plugin_author, plugin_version,   \
               plugin_definition)                                              \
  namespace {                                                                  \
  class plugin_name final : public plugin_interface plugin_definition;         \
                                                                               \
  inline auto get_instance() -> plugin_interface * {                           \
    static plugin_name instance;                                               \
    return &instance;                                                          \
  }                                                                            \
  extern "C" {                                                                 \
  [[gnu::unused]] plugin::ExportMeta<plugin_interface> export_meta = {         \
      .get_instance_ = get_instance,                                           \
      .name_ = #plugin_name,                                                   \
      .version_ = plugin_version,                                              \
      .author_ = plugin_author,                                                \
  };                                                                           \
  }                                                                            \
  }

/*
  Here we use ** extern "C" ** to prevent cpp compile change the name of
  the variable.

  But we still have two fucking annoying warnings:

  1. Variable 'export_meta' defined in a header file; variable definitions in
  header files can lead to ODR violations

  2. Function 'example::(anonymous namespace)::HelloFromHere::say_hello' has
  internal linkage but is not defined
*/

} // namespace plugin