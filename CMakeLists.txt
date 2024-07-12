cmake_minimum_required(VERSION 3.18)# Проверка версии CMake. Если версия установленой программы
                                    # старее указаной, произайдёт аварийный выход.

roject(pacman)                      # Название проекта

set(CMAKE_CXX_STANDARD 17)          # Этой функцией вы устанавливаете требование определенного языкового стандарта - C++  
                                    # В данном случае это 20 версия языка программирования С++ (Максимальная на данный момент 23)
target_compile_options(-pthread)    # Эта команда используется для добавления специфичных флагов компилятора

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

                                    # Указывает на исполняемые проекта
add_executable(pacman main.cpp settings.cpp settings.h rendering.cpp 
                    rendering.h erproc.cpp erproc.h 1bitinput.cpp 1bitinput.h) 