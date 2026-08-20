#pragma once

#include <libhttp/config.hpp>
#include <libhttp/core/body.hpp>
#include <libhttp/core/headers.hpp>
#include <libhttp/core/method.hpp>
#include <libhttp/core/uri.hpp>


namespace libhttp {

  class LIBHTTP_API Request {

    public:
      Request() = default;

      Request(Method method, Uri uri);

      [[nodiscard]]
      Method method() const noexcept;

      void method(Method method) noexcept;

      [[nodiscard]]
      const Uri& uri() const noexcept;

      void uri(Uri uri);

      [[nodiscard]]
      Headers& headers() noexcept;


      [[nodiscard]]
      const Headers& headers() const noexcept;

      [[nodiscard]]
      Body& body() noexcept;

      [[nodiscard]]
      const Body& body() const noexcept;

    private:
      Method method_{Method::GET};
      Uri uri_;
      Headers headers_;
      Body body_;
  };
} // namespace libhttp
