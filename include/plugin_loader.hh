#pragma once

#include "plugin_declare.hh"
#include <dlfcn.h>
#include <filesystem>
#include <functional>
#include <stdexcept>
#include <string>

namespace plugin {

template <typename Interface> class Loader {
  using handler_t = const std::function<Interface *()>;

public:
  Loader(const std::filesystem::path &plugin_path) {
    dl_handle_ = ::dlopen(plugin_path.c_str(), RTLD_LAZY);
    if (dl_handle_ == nullptr) {
      throw std::runtime_error(std::string(dlerror()));
    }
    meta_ =
        reinterpret_cast<decltype(meta_)>(::dlsym(dl_handle_, "export_meta"));
    if (meta_ == nullptr) {
      throw std::runtime_error(std::string(dlerror()));
    }
    instance_ = meta_->get_instance_();
  }

  ~Loader() {
    if (dl_handle_ != nullptr) {
      ::dlclose(dl_handle_);
    }
  }

public:
  auto operator->() -> Interface * { return instance_; }
  auto get_name() -> const char * { return meta_->name_; }
  auto get_version() -> const char * { return meta_->version_; }
  auto get_author() -> const char * { return meta_->author_; }

private:
  void *dl_handle_{nullptr};
  Interface *instance_{nullptr};
  const ExportMeta<Interface> *meta_{nullptr};
};

} // namespace plugin