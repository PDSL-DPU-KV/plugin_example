#pragma once

namespace example {

class AppHelloPluginInterface {
public:
  virtual ~AppHelloPluginInterface() = default;
  virtual auto say_hello() -> void = 0;
};

} // namespace example