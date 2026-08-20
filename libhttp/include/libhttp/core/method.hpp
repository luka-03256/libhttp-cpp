#pragma once

#include <libhttp/config.hpp>
#include <string_view>


namespace libhttp {

  enum class Method {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE_,
    CONNECT,
    OPTIONS,
    TRACE,
    PATCH
  };

  LIBHTTP_API std::string_view to_string(Method method) noexcept;

  LIBHTTP_API Method method_from_string(std::string_view value);
} // namespace libhttp
