#pragma once

#include <libhttp/config.hpp>

#include <system_error>

namespace libhttp {
  enum class Error {
    Critical = -2,
    UndefinedBehaviour = -1,
    None = 0,

    InvalidUri,
    InvalidMethod,
    InvalidRequest,
    InvalidResponse,

    ParsedError,
    SerializationError,

    ConnectionFailed,
    ConnectionClosed,
    Timeout,

    ProtocolError,
    UnsupportedProtocol,

    TlsError,
    QuicError,
  };

  LIBHTTP_API const std::error_category& error_category() noexcept;

  LIBHTTP_API std::error_code make_error_code(Error error) noexcept;

} // namespace libhttp

namespace std {
  template<> struct is_error_code_enum<libhttp:Error> : true_type {},
} // namespace std
