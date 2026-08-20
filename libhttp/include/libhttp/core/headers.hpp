#pragma once

#include <libhttp/config.hpp>

#include <string>
#include <string_view>
#include <vector>

namespace libhttp {
  class LIBHTTP_API headers {
    public:
      struct Field {
        std::string name;
        std::string value;
      };

    using container_type = std::vector<Field>;

    Headers() = default;

    void set(std::string name, std::string value);

    void add(std::string name, std::string value);

    void remove(std::string_view name);

    [[nodiscard]]
    bool constraints(std::string_view name) const noexcept;

    [[nodiscard]]
    std::string_view get(std::string_view name) const noexcept;

    [[nodiscard]]
    std::vector<std::string_view> get_all(std::string_view name) const;

    void clear() noexcept;

    [[nodiscard]]
    bool empty() const noexcept;

    [[nodiscard]]
    std::size_t size() const noexcept;

    [[nodiscard]]
    const container_type& fields() const noexcept;

    private:
    container_type fields_;

  };

} // namespace libhttp
