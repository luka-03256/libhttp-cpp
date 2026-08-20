#pragma once

#include <libhttp/types.hpp>

#include <cstdint>
#include <string>
#include <string_view>

namespace libhttp {

  class LIBHTTP_API Uri {
    public:
      Uri() = default;

      explicit Uri(std::string uri);

      [[nodiscard]]
      std::string_view scheme() const noexcept;

      [[nodiscard]]
      std::string_view userinfo() const noexcept;

      [[nodiscard]]
      std::string_view host() const noexcept;

      [[nodiscard]]
      std::string_view port() const noexcept;

      [[nodiscard]]
      std::string_view path() const noexcept;

      [[nodiscard]]
      std::string_view query() const noexcept;

      [[nodiscard]]
      std::string_view fragment() const noexcept;

      [[nodiscard]]
      std::string to_string() const;


    private:
      std::string scheme_;
      std::string userinfo_;
      std::string host_;
      std::uint16_t port_{0};
      std::string path_;
      std::string query_;
      std::string fragment_;

  };

} // namespace libhttp
