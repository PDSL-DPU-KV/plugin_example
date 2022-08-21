#include "hello_from_there_impl.hh"

#include <iostream>

namespace example {

auto HelloFromThere::say_hello() -> void {
  std::cout << "hello from there" << std::endl;
}

} // namespace example