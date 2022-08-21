#pragma once

#include "hello_plugin_interface.hh"
#include "plugin.hh"

namespace example {

PlugIn(HelloFromHere, AppHelloPluginInterface, "HammerLi", "v0.0.1", {
public:
  auto say_hello()->void override;
});

}