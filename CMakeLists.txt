# CMakeList.txt: проект CMake для simple_genetic_algorithm; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("simple_genetic_algorithm")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (simple_genetic_algorithm "simple_genetic_algorithm.cpp" "simple_genetic_algorithm.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
