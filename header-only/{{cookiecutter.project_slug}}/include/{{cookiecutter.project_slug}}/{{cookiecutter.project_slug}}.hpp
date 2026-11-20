#pragma once

#include <string_view>

namespace {{ cookiecutter.project_slug }}
{
constexpr std::string_view version() noexcept
{
    return "{{ cookiecutter.version }}";
}
}
