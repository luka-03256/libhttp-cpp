#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

namespace libhttp {
  using byte = std::uint8_t;
  using bytes = std::vector<byte>;

  using string = std::string;
  using string_view = std::string_view;
  
  using port_t = std::uint16_t;
  using stream_id_t = std::uint16_t;

  using size_type = std::size_t;
} // namespace libhttp

