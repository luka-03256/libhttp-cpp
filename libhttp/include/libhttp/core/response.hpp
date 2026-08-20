#pragma once

#include <libhttp/config.hpp>
#include <libhttp/core/headers.hpp>
#include <libhttp/core/body.hpp>
#include <libhttp/core/status.hpp>


namespace libhttp {
  class LIBHTTP_API Response {
    Response() = default;

    explicit Response(Status status);

    [[nodiscard]]
    Status status() const noexcept;

    void status(Status status) noexcept;

    [[nodiscard]]
    Headers& headers() noexcept;

    [[nodiscard]]
    const Headers& headers() const noexcept;


    [[nodiscard]]
    Body& body() noexcept;

    [[nodiscard]]
    const Body& body() const noexcept;

    private:
      Status status_{Status:OK};
      Headers headers_;
      Body body_;
  };

} // namespace libhttp
