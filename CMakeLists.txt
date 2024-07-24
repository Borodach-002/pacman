cmake_minimum_required(VERSION 3.10)

# Укажите название проекта
project(MyCppProject)

# Укажите стандарт языка C++
set(CMAKE_CXX_STANDARD 17)

# Добавьте все исходные файлы проекта
set(SOURCES
    main.cpp
    settings.cpp
    rendering.cpp
    erproc.c
    1bitinput.cpp
)

# Укажите заголовочные файлы
set(HEADERS
    settings.h
    rendering.h
    erproc.h
    1bitinput.h
)

# Создайте исполняемый файл из исходных файлов
add_executable(MyCppProject ${SOURCES} )

# Найдите и подключите необходимые библиотеки
find_package(Threads REQUIRED)
if(UNIX AND NOT APPLE)
    target_link_libraries(MyCppProject PRIVATE Threads::Threads)
    target_link_libraries(MyCppProject PRIVATE rt)  # для POSIX realtime extensions, если используются
    target_link_libraries(MyCppProject PRIVATE m)   # для математической библиотеки
    target_link_libraries(MyCppProject PRIVATE dl)  # для dlopen и др. динамических библиотек
endif()