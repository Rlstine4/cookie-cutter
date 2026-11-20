#pragma once

#include <string_view>

#include "{{ cookiecutter.project_slug }}/{{ cookiecutter.project_slug }}_export.h"

namespace {{ cookiecutter.project_slug }}
{
{{ cookiecutter.project_slug | upper }}_EXPORT std::string_view version() noexcept;
}
