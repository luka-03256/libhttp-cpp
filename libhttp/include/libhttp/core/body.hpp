#pragma once


#include <libhttp/types.hpp>

namespace libhttp {

  class LIBHTTP_API Body {
    public:
      Body() = default;

      explicit Body(std::string data);
      explicit Body(bytes data);

      [[nodiscard]]
      bool empty() const noexcept;

      [[nodiscard]]
      std::size_t size() const noexcept;

      [[nodiscard]]
      const bytes& data() const noexcept;

      [[nodiscard]]
        std::string_view as_string() const noexcept;

    private:
      bytes data_;

  };

} // namespace libhttp
