#include <catch2/catch_test_macros.hpp>

#include "{{ cookiecutter.project_slug }}/{{ cookiecutter.project_slug }}.hpp"

TEST_CASE("version is exposed", "[{{ cookiecutter.project_slug }}]")
{
    STATIC_REQUIRE({{ cookiecutter.project_slug }}::version() == "{{ cookiecutter.version }}");
}
