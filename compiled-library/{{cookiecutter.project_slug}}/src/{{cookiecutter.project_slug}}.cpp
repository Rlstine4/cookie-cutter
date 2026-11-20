#include "{{ cookiecutter.project_slug }}/{{ cookiecutter.project_slug }}.hpp"

namespace {{ cookiecutter.project_slug }}
{
std::string_view version() noexcept
{
    return "{{ cookiecutter.version }}";
}
}
