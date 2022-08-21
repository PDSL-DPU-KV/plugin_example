#include "hello_from_here_impl.hh"

#include <iostream>

namespace example {

auto HelloFromHere::say_hello() -> void {
  std::cout << "hello from here" << std::endl;
}

} // namespace example